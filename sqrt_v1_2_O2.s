	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 18, 4
	.file	"sqrt_v1_2.c"
	.text
	.align	2
	.global	calculate_sqrt
	.type	calculate_sqrt, %function
calculate_sqrt:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r3, #1
	stmfd	sp!, {r4, r5}
	mov	r4, r3, asl r0
	subs	r5, r0, #1
	mov	r1, r1, asl r0
	moveq	r0, r4
	beq	.L3
	mov	r0, r4
	mov	ip, #0
.L5:
	mov	r3, ip, asl #1
	add	r3, r4, r4, lsr r3
	mov	r2, r4, asl #1
	add	r3, r3, r2, lsr ip
	cmp	r1, r3
	addcs	r0, r0, r0, lsr ip
	add	ip, ip, #1
	movcs	r4, r3
	cmp	r5, ip
	bne	.L5
.L3:
	ldmfd	sp!, {r4, r5}
	bx	lr
	.size	calculate_sqrt, .-calculate_sqrt
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, lr}
	mov	r1, #2
	mov	r0, #14
	bl	calculate_sqrt
	mov	r1, r0
	ldr	r0, .L11
	bl	printf
	mov	r0, #0
	ldmfd	sp!, {r4, lr}
	bx	lr
.L12:
	.align	2
.L11:
	.word	.LC0
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"%d\012\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
