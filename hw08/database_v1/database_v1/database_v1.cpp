/*
Employee database Version 1.0

Uses three separate global arrays to hold the databse
One array for the first name, one array for the last name,
and one array for the salary.

Allows addition of an employee, deletion of an employee,
screen printout of the entire employee list,
and modification of an employee's salary.

Last names are unique enough to identify an employee.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

// The maximum number of records in the database
#define MAX 5

// the data
char lname[MAX][80], fname[MAX][80];
double sal[MAX];

// function prototypes
void print_menu();
void add();
void modify();
void del();
void list();
int find(char *);
void make_cap(char *);
void save();

int main()
{
	char ch; // menu IO
	print_menu();

	// Main Menu Loop
	do {
		ch = getche();
		switch (ch) {
			case 'a':
			case 'A':
				add();
				break;
			case 'm':
			case 'M':
				modify();
				break;
			case 'l':
			case 'L':
				list();
				break;
			case 'd':
			case 'D':
				del();
				break;
			case 's':
			case 'S':
				save();
				break;
			case 'q':
			case 'Q':
				printf("\n");
				break;
			default:
				printf("\nPlease re-enter: ");
		}
	} while (toupper(ch) != 'Q');
}

// Make a string all caps
void make_cap(char *str)
{
	int i = 0;
	while (str[i])
		str[i++] = toupper(str[i]);
}

// Displays the main menu
void print_menu()
{
	printf("\n");
	printf("\tAdd Employee\n");
	printf("\tModify Employee's Salary\n");
	printf("\tList Employees\n");
	printf("\tDelete Employee\n");
	printf("\tSave File\n");
	printf("\tQuit\n");

	printf("Enter [a, m, l, d, s, q]: ");
}

// Prints out the entire database
void list()
{
	int i;

	//Display table heading
	printf("\n%-20s%-20s%+13s\n", "Last", "First", "Salary");
	printf("-----------------------------------------------------\n");

	// Print data. Skip blank records.
	for (i = 0; i < MAX; i++) {
		if (lname[i][0]) {
			printf("%-20s%-20s%10.2lf\n", lname[i], fname[i], sal[i]);
		}
	}

	printf("\nPress any key to continue. ");
	getch();
	printf("\n");
	print_menu();
}

// Deletes an employee
void del()
{
	char str[80], ch;
	int i;

	// find the index of the employee in the database
	printf("\nEnter last name to delete: ");
	fflush(stdin);
	gets(str);
	make_cap(str);
	i = find(str);

	// bail if employee not found
	if (i == -1) {
		printf("Employee not found. Press any key to continue. ");
		getch();
		print_menu();
		return;
	}

	// display employee info
	printf("\n%-20s%-20s%+13s\n", "Last", "First", "Salary");
	printf("-----------------------------------------------------\n");
	printf("%-20s%-20s%10.2lf\n", lname[i], fname[i], sal[i]);

	// ask user to confirm deletion
	printf("Delete this employee (y/n)? ");
	ch = getche();

	// bail if any char other than y or Y
	if (toupper(ch) != 'Y') return;

	// do deletion
	lname[i][0] = '\0';

	print_menu();
}

// Searches the databse for a desired lname
// Returns index or -1 if not found
int find(char *str) {
	int i;

	for (i = 0; i < MAX; i++) {
		if (!strcmp(str, lname[i]))
			return i;
	}

	// not found
	return -1;
}

// Modifies an employees record
void modify()
{
	char str[80];
	int i;

	// find index of this employee in the database
	printf("\nEnter last name to modify: ");
	fflush(stdin);
	gets(str);
	make_cap(str);
	i = find(str);

	// bail if employee not found
	if (i == -1) {
		printf("Employee not found. Press any key to continue. ");
		getch();
		print_menu();
		return;
	}

	// display employee info
	printf("\n%-20s%-20s%+13s\n", "Last", "First", "Salary");
	printf("-----------------------------------------------------\n");
	printf("%-20s%-20s%10.2lf\n", lname[i], fname[i], sal[i]);

	printf("Enter new salary: ");
	scanf("%lf", &sal[i]);

	print_menu();
}

// Adds an employee to the database
void add()
{
	char str[80];
	int i;

	// find a blank place to put this new record
	for (i = 0; i < MAX; i++) {
		if (!lname[i][0])
			break;
	}

	// is the database full?
	if (i >= MAX) {
		printf("\nDatabse is full. Press any key to continue. ");
		getche();
		print_menu();
		return;
	}

	// get data from user and put in database
	printf("\nEnter last name: ");
	fflush(stdin);
	gets(str);
	make_cap(str);
	strcpy(lname[i], str);

	printf("Enter first name: ");
	gets(str);
	make_cap(str);
	strcpy(fname[i], str);
	
	printf("Enter salary: ");
	scanf("%lf", &sal[i]);
	
	print_menu();
}

// Saves the database to a text file
void save()
{
	int i;
	FILE *f;
	char filename[80];

	// prompt user for name of file
	printf("\nPlease enter name of file: ");
	fflush(stdin);
	gets(filename);

	// open text file for output
	if ((f = fopen(filename, "w")) == NULL) {
		printf("Error opening text output file.\n");
		print_menu();
		return;
	}

	// write data. skip blank records
	for (i = 0; i < MAX; i++) {
		if (lname[i][0]) {
			fprintf(f, "%-20s%-20s%10.2lf\n", lname[i], fname[i], sal[i]);
		}
	}

	fclose(f); // close the file

	printf("\nFile saved. Press any key to continue. ");
	getch();
	printf("\n");
	print_menu();
}