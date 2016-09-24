#!/bin/sh
# проевить на отрицатальные ноль и буквы
./1_lab_2 253 $input > output1.out
./1_lab_2 222 $input > output2.out

if cmp output1.out rightOutput1.out && cmp output2.out rightOutput2.out
then echo "Test successed!"
else echo "!! FAIL !! ($?)"
fi
