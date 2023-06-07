## Header :
.name "Jigglypuff"
.comment "A great pokemon"

## Body :
    sti r1, %:sleep, %1
sleep:
    live %234
    ld %0, r3
    zjmp %:sleep
