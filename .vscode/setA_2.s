.data

	matC:	.word	0:9

	sizeA:	.word	3, 3	
	matA:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9

	sizeB:	.word	4, 3
	matB:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9


	prompt1:	.asciiz "not compatible"
	prompt2:	.asciiz	"process done"

.text
	.globl main
	main:

		la $s0, matA    
	        la $s1, matB    
	        la $s2, sizeA       
        	nop
        	lw $s3, 4($s2)      
        	nop
        	lw $s2, 0($s2)      
       		la $s4, sizeB       
       		nop
        	lw $s5, 4($s4)      
        	nop
     		lw $s4, 0($s4)      
     
		jal checkDim
		beq $v0, $zero, exit1


		la $s6, matC
		jal matMul


        	exit:
		la $a0, prompt2
		li $v0, 4
		syscall
		li $v0, 10
		syscall

		exit1:
		la $a0, prompt1
		li $v0, 4
		syscall
		li $v0, 10
		syscall

#############################################################################################################

	.globl	checkDim
	checkDim:
		add $v0, $zero, $zero
		bne $s3, $s4, notEqual
		addi $v0, $zero, 1
	notEqual:
		jr $ra

#############################################################################################################


	.globl matMul
	matMul:
		add $s7, $s5, $zero 	
        	add $t0, $zero, $zero   
        	add $t1, $zero, $zero   
        	add $t2, $zero, $zero   
        	li  $t3, 0       

		li  $t4, 4
		mul $s2, $s2, $t4
		mul $s4, $s4, $t4
		mul $s5, $s5, $t4

i_loop: 	beq $t0, $s2, i_end 
        	nop
j_loop: 	beq $t1, $s5, j_end 
        	nop
k_loop: 	beq $t2, $s4, k_end #End k_loop if k = rowsB
        	nop


	        li $t4, 0
	        li $t5, 0
	        li $t6, 0
                            
	        mul  $t4, $t0, $s3   
	        add  $t4, $t4, $t2   
	        addi $t4, $t4, -4      
	        add  $t4, $t4, $s0   
	        lw   $t4, 0($t4)      

	        mul  $t5, $t2, $s5   
	        add  $t5, $t5, $t1   
	        addi $t5, $t5, -4  
	        add  $t5, $t5, $s1   
	        lw   $t5, 0($t5)      

                    
	        mul  $t6, $t0, $s7   
	        add  $t6, $t6, $t1   
	        addi $t6, $t6, -4  
	        add  $t6, $t6, $s6   
	        lw   $t8, 0($t6)      

	        mul $t7, $t4, $t5   

	        add $t9, $t8, $t7   
	        sw  $t9, 0($t6)


        	addi $t2, $t2, 4   
        	j k_loop        
	k_end:
        	addi $t1, $t1, 4    
        	li $t2, 0       
        	j j_loop        
	j_end:
        	addi $t0, $t0, 4    
       	 	li $t1, 0       
        	j i_loop        

	i_end:

		jr $ra
