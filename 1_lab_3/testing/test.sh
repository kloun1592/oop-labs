#!/bin/sh

successAnswer="test passed"
unseccessAnswer="!! FAIL !!"
programToBeTestedLocation="../exec_files/"
programToBeTested="1_lab_3"

#1 параметр - имя программы, проходящей тестирование
#2 параметр - первый файл для тестирования
#3 параметр - второй файл для тестирования
#4 параметр - номер теста

createOutputFile()
{
    ${programToBeTestedLocation}${1} ${2} ${3} $input > ./temp_out/output${4}.out
}

test()
{
  createOutputFile ${1} ${2} ${3} ${4}
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

test $programToBeTested ${testsInputFilesFolder}matrix1.txt ${testsInputFilesFolder}matrix2.txt ${testNumber}

testNumber=2
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}matrix1.txt ${testsInputFilesFolder}matrix2.txt ${testNumber}

testNumber=3
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}matrix1.txt ${testsInputFilesFolder}matrix2.txt ${testNumber}

testNumber=4
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}matrix1.txt ${testsInputFilesFolder}matrix2.txt ${testNumber}

testNumber=5
testsInputFilesFolder="./tests_input_files/${testNumber}_test_input_files/"

test $programToBeTested ${testsInputFilesFolder}matrix1.txt ${testsInputFilesFolder}matrix2.txt ${testNumber}
