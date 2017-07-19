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
	mov	r3, #1 // r3 = 1
	stmfd	sp!, {r4, r5, r6} // 
	mov	r4, r3, asl r0 // r4 = f = 1 << K
	subs	r6, r0, #1 // r6 = K-1
	mov	r5, r1, asl r0 // r5 = M << K
	moveq	r0, r4 // r0 = f_sqrt = 1 << K
	beq	.L3 
	mov	r0, r4 // r0 = f_sqrt (REDUNDANT?)
	mov	ip, #0 // ip = i = 0
.L8:
	mov	r3, ip, asl #1 // r3 = i << 1
	add	r3, r4, r4, lsr r3 // r3 = f >> (i << 1)
	mov	r2, r4, asl #1 // r2 = f << 1
	add	r3, r3, r2, lsr ip // r3 = f >> (i << 1) + (f << 1) >> i
	add	r1, r0, r0, lsr ip // r1 = f_sqrt + f_sqrt >> i
	cmp	r5, r3 // MU <= M
	add	ip, ip, #1 // i++
	movcs	r4, r3 // r4 = f >> (i << 1) + (f << 1) >> i
	movcs	r0, r1 // r0 = f_sqrt = f_sqrt + f_sqrt >> i
	cmp	r6, ip // loop termination check
	bne	.L8 //
.L3:
	ldmfd	sp!, {r4, r5, r6}
	bx	lr
	.size	calculate_sqrt, .-calculate_sqrt
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	mov	r1, #23040
	stmfd	sp!, {r4, lr}
	add	r1, r1, #128
	ldr	r0, .L14
	bl	printf
	mov	r0, #0
	ldmfd	sp!, {r4, lr}
	bx	lr
.L15:
	.align	2
.L14:
	.word	.LC0
	.size	main, .-main
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC0:
	.ascii	"%d\012\000"
	.ident	"GCC: (Sourcery G++ Lite 2008q3-72) 4.3.2"
	.section	.note.GNU-stack,"",%progbits
