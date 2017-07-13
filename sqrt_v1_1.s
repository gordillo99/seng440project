	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"sqrt_v1_1.c"
	.text
	.align	2
	.global	calculate_sqrt
	.type	calculate_sqrt, %function
calculate_sqrt:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #36
	str	r0, [fp, #-32]
	str	r1, [fp, #-36]
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-36]
	mov	r3, r3, asl r2
	str	r3, [fp, #-36]
	ldr	r2, [fp, #-32]
	mov	r3, #1
	mov	r3, r3, asl r2
	str	r3, [fp, #-20]
	ldr	r2, [fp, #-32]
	mov	r3, #1
	mov	r3, r3, asl r2
	str	r3, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L2
.L4:
	ldr	r2, [fp, #-32]
	mov	r3, #1
	mov	r1, r3, asl r2
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-24]
	rsb	r3, r3, r2
	mov	r2, r3
	mov	r3, #2
	mov	r3, r3, asl r2
	add	r0, r1, r3
	ldr	r2, [fp, #-32]
	mov	r3, #1
	mov	r1, r3, asl r2
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-24]
	rsb	r3, r3, r2
	mov	r2, r3
	mov	r3, #2
	mov	r3, r3, asl r2
	add	r3, r1, r3
	mul	r2, r3, r0
	ldr	r3, [fp, #-32]
	mov	r3, r2, asr r3
	mov	r2, r3
	ldr	r3, [fp, #-20]
	mul	r2, r3, r2
	ldr	r3, [fp, #-32]
	mov	r3, r2, lsr r3
	str	r3, [fp, #-12]
	ldr	r2, [fp, #-32]
	mov	r3, #1
	mov	r1, r3, asl r2
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-24]
	rsb	r3, r3, r2
	mov	r2, r3
	mov	r3, #2
	mov	r3, r3, asl r2
	add	r3, r1, r3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	mul	r2, r3, r2
	ldr	r3, [fp, #-32]
	mov	r3, r2, lsr r3
	str	r3, [fp, #-8]
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-36]
	cmp	r2, r3
	bhi	.L3
	ldr	r3, [fp, #-12]
	str	r3, [fp, #-20]
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-16]
.L3:
	ldr	r3, [fp, #-24]
	add	r3, r3, #1
	str	r3, [fp, #-24]
.L2:
	ldr	r3, [fp, #-32]
	sub	r2, r3, #1
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	bhi	.L4
	ldr	r3, [fp, #-16]
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	calculate_sqrt, .-calculate_sqrt
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%d\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #14
	str	r3, [fp, #-12]
	ldr	r2, [fp, #-12]
	mov	r3, #6
	mov	r3, r3, asl r2
	str	r3, [fp, #-8]
	ldr	r0, [fp, #-12]
	ldr	r1, [fp, #-8]
	bl	calculate_sqrt
	mov	r3, r0
	ldr	r0, .L8
	mov	r1, r3
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L9:
	.align	2
.L8:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits