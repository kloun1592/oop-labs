#!/bin/sh

successAnswer="test passed"
unseccessAnswer="!! FAIL !!"
programToBeTested="1_lab"

test()
{
  ../exec_files/Debug/${1} ${2} ${3} $input > ./temp_out/output${4}.out
  if cmp ./temp_out/output${4}.out ./right_answers/rightOutput${4}.out;
  then
    echo "$4 $successAnswer"
    rm ./temp_out/output${4}.out
  else
    echo "$unseccessAnswer ($?)"
  fi
}

testNumber=1
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}input1.txt ${testsInputFilesFolder}input2.txt ${testNumber}

testNumber=2
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}input1.txt ${testsInputFilesFolder}input2.txt ${testNumber}

testNumber=3
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}input1.txt ${testsInputFilesFolder}input2.txt ${testNumber}

testNumber=4
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}input1.txt ${testsInputFilesFolder}input2.txt ${testNumber}
