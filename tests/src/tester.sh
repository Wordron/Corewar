#!/bin/bash


# Test Jon Snow
CHAMPION="jon"
echo "Test Jon Snow :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test Abel
CHAMPION="abel"
echo "Test Abel :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test Bill
CHAMPION="bill"
echo "Test Bill :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test pdd
CHAMPION="pdd"
echo "Test pdd :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test Tyron
CHAMPION="tyron"
echo "Test Tyron :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test No_comment
CHAMPION="no_comment"
echo "Test No_comment :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

# Test No_name
CHAMPION="no_name"
echo "Test No_name :"
./asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_our_asm.cor && rm ${CHAMPION}.cor
./tests/corewar_binaries/asm/asm tests/corewar_binaries/corewar/assets/champions/src/${CHAMPION}.s && cp ${CHAMPION}.cor output_ref_asm.cor && rm ${CHAMPION}.cor
cmp "output_our_asm.cor" "output_ref_asm.cor"
if [ $? -eq 0 ]
then
    echo  -en  "\033[92msuccess !\033[00m"; echo
else
    echo  -en  "\033[91mfailure !\033[00m"; echo
    echo 'Ref :'
    hexdump -C output_ref_asm.cor
    echo 'Our :'
    hexdump -C output_our_asm.cor
    echo
fi

rm output_our_asm.cor output_ref_asm.cor
