.data
numb1:	.word	0xFFFFFFFF
numb2:	.word	0xFFFFFFFF
numb3:	.word	0
result:	.word	0	#0 if positive, 1 if negaive, 2 if overflow

.text
	.globl main
	main:
		lw	$s1, numb1
		lw	$s2, numb2
		lui	$t0, 0x8000		#Bit-masking digit for last bit

		and	$t1, $s1, $t0		#Bit-masking of 1st number, creating A
		and	$t2, $s2, $t0		#Bit-masking of 2nd number, creating B
		and	$t4, $t1, $t2		#Creating AB
		
		add	$s3, $s1, $s2		#Addition of both numbers
		sw	$s3, numb3		#Storing back the sum
		and	$t3, $s3, $t0		#Bit-masking of sum, creating C
		
		add	$t5, $zero, $zero	#Generating comp(A)
		beq	$t1, $t0, doneA
		add	$t5, $t0, $zero

		doneA:

		add	$t6, $zero, $zero	#Generating comp(B)
		beq	$t2, $t0, doneB
		add	$t6, $t0, $zero

		doneB:

		add	$t7, $zero, $zero	#Generating comp(C)
		beq	$t3, $t0, doneC
		add	$t7, $t0, $zero

		doneC:

		and	$t4, $t4, $t7		#Generating AB[comp(C)]
		and	$t8, $t5, $t6		#Generating comp(A)comp(B)
		and	$t8, $t8, $t3		#Generating comp(A)comp(B)C
		
		or	$t4, $t4, $t8		#Generating AB[comp(C) + comp(A)comp(B)C, if it is equal to 0x80000000 then overflow occured
		
		add	$s0, $zero, $zero	#checking for positive or negative
		bne	$t3, $t0, pos
		addi	$s0, $zero, 1

		pos:

		bne	$t4, $t0, NOver		#checking overflow occured or not	
		addi	$s0, $zero, 2

		NOver:
		sw	$s0, result
		
		li	$v0, 10
		syscall
