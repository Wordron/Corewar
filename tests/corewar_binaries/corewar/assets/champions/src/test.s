	.name "Test"
	.comment "To test all kind of things"

	sti r1, %:hi, %1

hi:	live %234
	ld %0, r3
	zjmp %:hi
