#!/bin/bash

#	This script is used for comparing output, from program written in C language, with the correct output.

if test -z $1												# Argument for this script must not be empty.
	then
		echo "You must put an execute file as an argument.";
		exit 1;
fi


if ! test -x $1  											# Argument must be an execute file.
	then
		echo "$1 is not an execute file.";
		exit 2;
fi

if ! test -d data											# There must be a directory called 'data' with the correct inputs and outputs.
	then
		echo "There is no 'data' directory for testing."
		exit 3;
fi

echo "";												# For good-looking final output of this script.

testNumber=1												# Variable defining each test.
success=0												# Variable defining a success test.
for inputFile in $(ls data/*.in)	
	do

		./$1 < $inputFile > result;								# Put every input files from 'data/' as a STDIN for the program. And print the result to the file called 'result'.
		
		inputFile="$(echo $inputFile | sed -E 's/.in/.ref/g')";					# Change input file to the file with the correct output.

		

		
		if diff result $inputFile > different							# Compare the output from your program with the correct output. If there is any differences put it to the file called 'different'
			then
				echo "Test $testNumber succesful!";					# Both output are the same.
				success=$(($success+1));						# Count this test as success test.
			
			else
				echo "Test $testNumber fail!";						# Outputs are different.
				echo "";
				cat different | sed -E 's/</Your program output:/g' > change		# Change the warning for better reading.
				cat change | sed -E 's/>/The correct output:/g' > final
				cat final;
				echo "";
				rm change final								# Remove the helping files.
		fi
	
		testNumber=$(($testNumber+1));								# Put the new number for another test.
		rm different										# Remove the helping file.

	done		

testNumber="$(($testNumber-1))";									# The last test put the new number, so we should put it back to know what was the number of the last test.

echo "";
echo "-------------------------";
echo "Success rate: 	$success/$testNumber";								# number of success tests / number of all tests
echo "Score:		$(( ($success*100)/$testNumber ))%";						# Counting how many percent of success was it.
echo "";

rm result												# Remove the helping file.
