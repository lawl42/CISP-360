// Database v2.0

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
#pragma warning (disable:4996)

#define INCR 5

// definition of an employee
struct employee {
	int ID;
	char lname[80];
	char fname[80];
	double sal;
};
struct employee * db;   // pointer to data

// global variables
int rec_count = 0;
int db_size = 0;
int nextID = 1;
char g_filename[80] = "";
char needsave = 0;

// function declarations
void print_menu();
void open(char *);
void add();
void modify();
void list();
void cmpr();
void del();
void save();
void quit();

// secondary function declarations
void initdb(int, int);
void make_cap(char *);
int find(char *);
void bsort(void * a, int num, int width, int(*compare)(void *elem1, void *elem2));
int comp1(struct employee **, struct employee **);
int comp2(struct employee **, struct employee **);
int comp3(struct employee **, struct employee **);
int comp4(struct employee **, struct employee **);

// initialize the array of pointers to the comparison functions
int(*compfunc[4])(struct employee ** a, struct employee ** b) = {
	comp1, comp2, comp3, comp4
};

void main(int argc, char * argv[])
{
	char ch;

	// check for too many command line arguments
	if (argc > 2) {
		printf("Usage: %s <data file name>\n", argv[0]);
		exit(1);
	}

	// check if user has supplied a file name on command line
	if (argc == 2) {

		// save filename
		strcpy(g_filename, argv[1]);

		// attempt to open file...
		open(g_filename);

	}
	else
	{
		// initialize empty database
		rec_count = 0;
		db_size = INCR;
		nextID = 1;

		// allocate some memory
		db = (employee *)malloc(sizeof(struct employee) * db_size);
		initdb(0, db_size - 1);
	}

	print_menu();

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
			case 'c':
			case 'C':
				cmpr();
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
				quit();
				break;
			default:
				printf("\nPlease re-enter: ");
		}
	} while (toupper(ch) != 'Q');

}

// Displays the main menu
void print_menu()
{
	printf("\n");
	printf("\tAdd Employee\n");
	printf("\tModify Employee's Salary\n");
	printf("\tList Employees\n");
	printf("\tCompress Database\n");
	printf("\tDelete Employee\n");
	printf("\tSave File\n");
	printf("\tQuit\n");
	printf("Enter [a, m, l, c, d, s, q]: ");
}

// Opens a file and loads it's contents into the database.
void open(char * filename)
{

	FILE *fp;
	int i;

	// open file
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		// initialize empty database
		rec_count = 0;
		needsave = 0;
		db_size = INCR;
		nextID = 1;

		// allocate some memory
		db = (employee *)malloc(sizeof(struct employee) * db_size);
		initdb(0, db_size - 1);
	}
	else
	{
		// read nextID and rec_count
		fread(&nextID, sizeof nextID, 1, fp);
		fread(&rec_count, sizeof rec_count, 1, fp);
		db_size = rec_count + INCR;

		// allocate memory
		db = (struct employee *) malloc(sizeof(struct employee) * (db_size));

		// read records
		for (i = 0; i < rec_count; i++)
			fread(&db[i], sizeof(struct employee), 1, fp);

		// initialize remaining records in database
		initdb(rec_count, db_size - 1);

		fclose(fp);
	}
}

// Adds an employee to the database
void add()
{
	char str[80];
	int i;
	struct employee * old_db;

	// find a blank place to put this new record
	for (i = 0; i < db_size; i++){
		if (!db[i].lname[0])
			break;
	}

	// make db bigger if full
	if (i >= db_size) {
		// store pointer
		old_db = db;

		// initialize empty database
		db_size += INCR;

		// allocate some memory
		db = (struct employee *) malloc(sizeof(struct employee) * db_size);
		initdb(0, db_size - 1);

		// copy old records to new db
		for (i = 0; i <= db_size - 1 - INCR; i++)
			db[i] = old_db[i];

		// deallocate the memory
		free(old_db);
	}

	// get data from user and put in database
	printf("\nEnter last name to add : ");
	fflush(stdin);
	gets(str);
	make_cap(str);
	strcpy(db[i].lname, str);

	printf("Enter first name to add : ");
	gets(str);
	make_cap(str);
	strcpy(db[i].fname, str);

	printf("Enter salary : ");
	scanf("%lf", &db[i].sal);

	db[i].ID = nextID++;

	rec_count++;
	needsave = 1;

	print_menu();
}

// Modify the salary of an employee
void modify() {
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
	printf("%-20s%-20s%10.2lf\n", db[i].lname, db[i].fname, db[i].sal);

	printf("Enter new salary: ");
	scanf("%lf", &db[i].sal);

	needsave = 1;

	print_menu();
}

// Prints out the entire database
void list()
{
	int i, j;
	int op;
	struct employee ** db_p;

	// bail if no records
	if (rec_count == 0)
	{
		printf("\nNo records exist. Press any key to continue. ");
		getch();
		print_menu();
		return;
	}

	// display submenu
	printf("\n\n");
	printf("\tSort by Which Field?\n");
	printf("\t--------------------\n");
	printf("\t1) ID\n");
	printf("\t2) Last Name\n");
	printf("\t3) First Name\n");
	printf("\t4) Salary\n");

	fflush(stdin);
	do {
		printf("\nEnter [1,2,3,4]: ");
		scanf("%d", &op);
	} while (op < 1 || op > 4);

	// get an array of pointers and point to it
	db_p = (employee **)malloc(rec_count * sizeof(struct employee *));

	// point to non blank records
	for (i = 0, j = 0; i < db_size; i++) {
		if (db[i].lname[0]) {
			db_p[j] = &db[i];
			j++;
		}
	}

	// sort the pointers
	bsort(db_p, rec_count, sizeof(struct employee *), (int(__cdecl*) (void *, void *)) *compfunc[op - 1]);

	// Display table heading
	printf("\n\n    ID Last                 First                    Salary\n");
	printf("----------------------------------------------------------\n");

	// Print data using array of pointers.  
	for (i = 0; i < rec_count; i++)
		printf("%6d %-20s %-20s %10.2lf\n", db_p[i]->ID, db_p[i]->lname, db_p[i]->fname, db_p[i]->sal);

	// give the memory back to the system
	free(db_p);

	// let user catch up to what is happening to them
	printf("\nPress any key to continue.");
	getch();
	print_menu();

}

// Compress the database
void cmpr() {
	struct employee ** db_p;
	
	// get an array of pointers and point to it
	db_p = (employee **)malloc(rec_count * sizeof(struct employee *));

	// point to non blank records
	for (int i = 0, j = 0; i < db_size; i++) {
		if (db[i].lname[0]) {
			db_p[j] = &db[i];
			j++;
		}
	}

	db = *db_p;

	print_menu();
}

// Delete an employee
void del() {
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
	printf("%-20s%-20s%10.2lf\n", db[i].lname, db[i].fname, db[i].sal);

	// ask user to confirm deletion
	printf("Delete this employee (y/n)? ");
	ch = getche();

	// bail if any char other than y or Y
	if (toupper(ch) != 'Y') return;

	// do deletion
	db[i].lname[0] = '\0';

	rec_count--;
	needsave = 1;

	print_menu();
}

// Creates or overwrites a file
void save()
{
	FILE *fp;
	int i;
	char filename[80] = "";

	// get filename
	printf("\nEnter file name [default: %s]: ", g_filename);
	fflush(stdin);
	gets(filename);

	// use default?
	if (!filename[0]) {
		strcpy(filename, g_filename);
	}

	// open file
	if ((fp = fopen(filename, "wb")) == NULL) {
		printf("error opening file\n");
		return;
	}

	// write nextID and rec_count
	fwrite(&nextID, sizeof nextID, 1, fp);
	fwrite(&rec_count, sizeof rec_count, 1, fp);

	// write non-blank records
	for (i = 0; i < db_size; i++)
		if (db[i].lname[0])
			fwrite(&db[i], sizeof(struct employee), 1, fp);

	fclose(fp);
	needsave = 0;

	// let user the file is saved
	printf("\nData Saved.  Press any key to continue.");
	getch();
	print_menu();
}

// Quit the program
void quit() {
	char ch;
	if (needsave) {
		printf("\nDo you want to save the databse (y/n)? ");
		ch = getche();
		if (toupper(ch) == 'Y')
			save();
	}
}

// Initialize the db to blank
void initdb(int i, int j) {
	for (i; i <= j; i++) {
		db[i].lname[0] = '\0';
	}
}

// Make a string all caps
void make_cap(char *str)
{
	int i = 0;
	while (str[i])
		str[i++] = toupper(str[i]);
}

// Searches the databse for a desired employee
int find(char *str) {
	int i;

	for (i = 0; i < db_size; i++) {
		if (!strcmp(str, db[i].lname))
			return i;
	}

	// not found
	return -1;
}

// bubble sort the db
void bsort(void * a, int num, int width, int(*compare)(void *, void *))
{
	int i, j;
	void * temp;  // a buffer
	int swaps;

	// allocate a temp value of the proper size
	temp = malloc(width);

	// bubble sort the array
	for (i = 0; i < num; i++) {
		swaps = 0;
		for (j = num - 1; j > i; j--) {
			if (compare((char *)a + (j * width), (char *)a + (j - 1) * width) < 0) {
				// swap the elements
				memcpy(temp, (char *)a + (j * width), width);
				memcpy((char *)a + (j * width), (char *)a + (j - 1) * width, width);
				memcpy((char *)a + (j - 1) * width, temp, width);

				swaps = 1;
			}
		}
		if (!swaps)
			return;
	}

	free(temp);
}

// Comparison functions
int comp1(struct employee ** a, struct employee ** b)
{
	return ((*a)->ID - (*b)->ID);
}

int comp2(struct employee ** a, struct employee ** b)
{
	return strcmp((*a)->lname, (*b)->lname);
}

int comp3(struct employee ** a, struct employee ** b)
{
	return strcmp((*a)->fname, (*b)->fname);
}

int comp4(struct employee ** a, struct employee ** b)
{
	return (int)((*a)->sal - (*b)->sal);

}