#!/bin/sh

successAnswer="test passed"
unseccessAnswer="!! FAIL !!"
programToBeTestedLocation="../exec_files/"
programToBeTested="1_lab_2"

#1 параметр - имя программы, проходящей тестирование
#2 параметр - число
#3 параметр - номер теста

createOutputFile()
{
    ${programToBeTestedLocation}${1} ${2} $input > ./temp_out/output${3}.out
}

test()
{
  createOutputFile ${1} ${2} ${3}
  if cmp ./temp_out/output${3}.out ./right_answers/rightOutput${3}.out;
  then
    echo "$3 $successAnswer"
    rm ./temp_out/output${3}.out
  else
    echo "$unseccessAnswer with argument: ${2}"
  fi
}

# 1 тест

testNumber=1
decimalNumber=10

test $programToBeTested $decimalNumber ${testNumber}

# 2 тест

testNumber=2
decimalNumber=-125

test $programToBeTested $decimalNumber ${testNumber}

# 3 тест

testNumber=3
decimalNumber=abc

test $programToBeTested $decimalNumber ${testNumber}

# 4 тест

testNumber=4
decimalNumber=abc

test $programToBeTested $decimalNumber ${testNumber}

# 5 тест

testNumber=5
decimalNumber=13a45b6c

test $programToBeTested $decimalNumber ${testNumber}

# 6 тест

testNumber=6
decimalNumber=9825790347590237452374502937450927345972304572934752093475203475

test $programToBeTested $decimalNumber ${testNumber}
