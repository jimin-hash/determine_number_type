/*!	\file		numbers_main.c
	\author		Jimin Park
	\date		2019-01-30
	\version	0.1

	determines what type of number, a number is that input by user and need to determine whether or not the number is one of the following:
	- A natural number (if not, report that it is an integer).
	- An odd or even number.
	- A prime number, or composite number.
	- A triangular number (traditional starting point of one, not zero).
	- A square number (traditional starting point of one, not zero).
	- A power of two.
	- A factorial.
	- A perfect, deficient, or abundant number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

// forward declaration
long long int getNumber();
int print(long long int num);
int RPrint(long long int num);
int intOrNaturalChk(long long int num);
int oddOrEvenChk(long long int num);
int primeOrCompositeChk(long long int num);
int triangularNumChk(long long int num);
int squareNumChk(long long int num);
int factorialNumChk(long long int num);
int perfectNumbersNumChk(long long int num);
int powerOfTwoNumChk(long long int num);

int main() {
	// Decalre num from getNumber() return value
	long long int num = getNumber();

	// Call print() for print number what user input
	print(num);

	// Call methods for determining what type of number is
	puts("");
	intOrNaturalChk(num);
	oddOrEvenChk(num);
	primeOrCompositeChk(num);
	triangularNumChk(num);
	squareNumChk(num);
	factorialNumChk(num);
	perfectNumbersNumChk(num);
	powerOfTwoNumChk(num);
}

/*!	 \fn long long int getNumber()
	 \return number
	 \param none

	 Check the user input number is valid and return
	 If user input non-numberic char program will be terminate
	 \note convert user input from char to int type */
long long int getNumber() {
	long long int number = 0;
	int userInput;

	userInput = getchar();

	// check the user input valid one by one char
	// if userinput is EOF, space or not alphabet char, then quit
	// else if userinput is '-' that mean negative number, so getchar() next char
	// else if userinput is natular number
	if (userInput == EOF || isspace(userInput) || isalpha(userInput) != 0) {
		puts("you did not enter a number!  quitting.");

		// program terminate, 1 = EXIT_FAILURE
		exit(1);
	}
	else if (userInput == '-') {
		userInput = getchar();
		while (isdigit(userInput)) {
			// convert char to int
			// number * 10 for make ones place. tens place. hundreds place.......
			// '0' is 48, for example char '1' - '0' = 49 - 48 = 1 
			number = number * 10 + (userInput - '0');

			// get next char
			userInput = getchar();
		}
		// make it negative number
		number *= -1;
	}
	else {
		while (isdigit(userInput)) {
			// convert char to int
			number = number * 10 + (userInput - '0');

			// get next char
			userInput = getchar();
		}
	}

	return number;
}

/*!	 \fn long long int print(long long int num)
	 \return 0
	 \param num The user input number

	 Determine call RPrint() or not and flip the sign of the number, if num is negative number. */
int print(long long int num) {
	puts("You entered...");

	// if the number is zero, print the character for zero and quit
	// else if the number is negative, print the character for negative, then flip the sign of the number. 
	//		then call RPrint on the number(the negated number, if the original number was negative).
	if (num == 0) {
		putchar((unsigned int)(num + '0'));
		return 0;
	}
	else if (num < 0) {
		num = num * -1;
		putchar('-');
	}
	RPrint(num);

	return 0;
}

/*!	 \fn long long int RPrint(long long int num)
	 \return 0
	 \param num from print()

	 Convert num from int to char just for print*/
int RPrint(long long int num) {
	// if the number is zero, quit. 
	// Recursively call rprint on the number divided by ten. 
	// Convert the remainder to its character - digit equivalent and print that character.
	if (num == 0)
		return 0;
	else if (num / 10)
		RPrint(num / 10);

	putchar(num % 10 + '0');

	return 0;
}

/*!	 \fn long long int intOrNaturalChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is natural number or integer */
int intOrNaturalChk(long long int num) {
	if (num >= 0)
		puts("The number is a natural number.");
	else
		puts("The number is an integer.");

	return 0;
}

/*!	 \fn long long int oddOrEvenChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is even number or odd number */
int oddOrEvenChk(long long int num) {
	if (num % 2 == 0)
		puts("The number is even.");
	else
		puts("The number is odd.");

	return 0;
}

/*!	 \fn long long int primeOrCompositeChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is prime number or not */
int primeOrCompositeChk(long long int num) {
	bool boolPrime = true;

	// Corner case ( 0 , 1 )
	if (num <= 1) {
		boolPrime = false;
	}
	else {
		for (long long int i = 2; i < num; i++) {

			if ((num % i) == 0) {
				boolPrime = false;
				break;
			}
		}
	}

	if (boolPrime == true)
		puts("The number is prime.");
	else
		puts("The number is composites.");

	return 0;
}

/*!	 \fn long long int triangularNumChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is triangular number or not */
int triangularNumChk(long long int num) {
	long long int sum = 1;
	long long int i = 2;

	// T(n) = T(n-1) + n
	while (sum < num) {
		sum += i;
		i++;
	}

	if (sum == num)
		puts("The number is triangular.");
	else
		puts("The number is not triangular.");

	return 0;
}

/*!	 \fn long long int squareNumChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is square number or not */
int squareNumChk(long long int num) {
	long double squareNum = sqrtl((long double)num);
	unsigned int int_squareNum = (unsigned int)squareNum;
	unsigned int squreChk = int_squareNum * int_squareNum;

	// number 0 is not square
	if (num != 0 && squreChk == num)
		puts("The number is square.");
	else
		puts("The number is not square.");

	return 0;
}

/*!	 \fn long long int factorialNumChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is factorial number or not */
int factorialNumChk(long long int num) {
	long long int fNum = 1;
	long long int f = 1;

	//formula to calculate factorial
	// iterator f that will increase by 1
	// fNum will keep to contain number that multiplay f with fNum
	while (fNum < num) {
		fNum *= f;
		f++;
	}

	// if num(user input number) doesn't not match with fNum(fatorial number), num is not factorial number
	if (fNum == num)
		puts("The number is a factorial");
	else
		puts("The number is not a factorial");

	return 0;
}

/*!	 \fn long long int perfectNumbersNumChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is perfect number or abundant number or deficient
	 \note negative number can not determine type of number as perfect, abundant, and deficient */
int perfectNumbersNumChk(long long int num) {
	long long int pfNum = 0;
	long long int remind;

	for (long long int i = 1; i < num; i++) {
		remind = num % i;

		if (remind == 0)
			pfNum += i;
	}

	if (num < 0)
		puts("Negative number can not determine type of number as perfect, abundant, and deficient.");
	else if (pfNum == num)
		puts("The number is perfect.");
	else if (pfNum > num)
		puts("The number is abundant.");
	else
		puts("The number is deficient.");

	return 0;
}

/*!	 \fn long long int powerOfTwoNumChk(long long int num)
	 \return 0
	 \param num The user input number

	 Determine the num is a power of two or not */
int powerOfTwoNumChk(long long int num) {
	long double pNum = 0;
	long double p = 0;
	bool boolPNum = false;

	while (pNum < num) {
		// calculate power of two
		pNum = pow(2, p);

		if (pNum == num) {
			boolPNum = true;
			break;
		}
		p++;
	}

	if (boolPNum == true)
		puts("The number is a power of two.");
	else
		puts("The number is not a power of two.");

	return 0;
}