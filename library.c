#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book
{
	int id;
	char name[50];
	char author[50];
	char category[30];
	float price;
	int issued;
};

struct Book books[MAX];
int count = 0;

void clearInputBuffer(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

void addBook(void)
{
	if (count >= MAX)
	{
		printf("Library is full!\n");
		return;
	}

	printf("Enter Book ID: ");
	if (scanf("%d", &books[count].id) != 1)
	{
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	for (int i = 0; i < count; i++)
	{
		if (books[i].id == books[count].id)
		{
			printf("Book ID already exists!\n");
			return;
		}
	}

	printf("Enter Book Name: ");
	scanf(" %49[^\n]", books[count].name);
	clearInputBuffer();
	printf("Enter Author Name: ");
	scanf(" %49[^\n]", books[count].author);
	clearInputBuffer();
	printf("Enter Category: ");
	scanf(" %29[^\n]", books[count].category);
	clearInputBuffer();
	printf("Enter Price: ");
	if (scanf("%f", &books[count].price) != 1)
	{
		clearInputBuffer();
		return;
	}
	clearInputBuffer();

	books[count].issued = 0;
	count++;
	printf("Book added successfully!\n");
}

void displayBooks(void)
{
	if (count == 0)
	{
		printf("No books available!\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		printf("\nBook ID: %d", books[i].id);
		printf("\nBook Name: %s", books[i].name);
		printf("\nAuthor: %s", books[i].author);
		printf("\nCategory: %s", books[i].category);
		printf("\nPrice: %.2f", books[i].price);
		printf("\nStatus: %s\n", books[i].issued ? "Issued" : "Available");
	}
}

void searchByID(void)
{
	int id;
	printf("Enter Book ID: ");
	if (scanf("%d", &id) != 1)
		return;

	for (int i = 0; i < count; i++)
	{
		if (books[i].id == id)
		{
			printf("\nBook Name: %s", books[i].name);
			printf("\nAuthor: %s", books[i].author);
			printf("\nCategory: %s\n", books[i].category);
			return;
		}
	}
	printf("Book not found!\n");
}

void searchByName(void)
{
	char name[50];
	int found = 0;
	printf("Enter Book Name: ");
	scanf(" %49[^\n]", name);

	for (int i = 0; i < count; i++)
	{
		if (strstr(books[i].name, name) != NULL)
		{
			printf("\nBook ID: %d", books[i].id);
			printf("\nBook Name: %s", books[i].name);
			printf("\nAuthor: %s\n", books[i].author);
			found = 1;
		}
	}
	if (!found)
		printf("Book not found!\n");
}

void issueBook(void)
{
	int id;
	printf("Enter Book ID to issue: ");
	if (scanf("%d", &id) != 1)
		return;

	for (int i = 0; i < count; i++)
	{
		if (books[i].id == id)
		{
			if (!books[i].issued)
			{
				books[i].issued = 1;
				printf("Book issued successfully!\n");
			}
			else
				printf("Book is already issued!\n");
			return;
		}
	}
	printf("Book not found!\n");
}

void returnBook(void)
{
	int id;
	printf("Enter Book ID to return: ");
	if (scanf("%d", &id) != 1)
		return;

	for (int i = 0; i < count; i++)
	{
		if (books[i].id == id)
		{
			if (books[i].issued)
			{
				books[i].issued = 0;
				printf("Book returned successfully!\n");
			}
			else
				printf("Book was not issued!\n");
			return;
		}
	}
	printf("Book not found!\n");
}

void updateBook(void)
{
	int id;
	printf("Enter Book ID to update: ");
	if (scanf("%d", &id) != 1)
		return;

	for (int i = 0; i < count; i++)
	{
		if (books[i].id == id)
		{
			printf("Enter New Book Name: ");
			scanf(" %49[^\n]", books[i].name);
			printf("Enter New Author Name: ");
			scanf(" %49[^\n]", books[i].author);
			printf("Enter New Category: ");
			scanf(" %29[^\n]", books[i].category);
			printf("Enter New Price: ");
			if (scanf("%f", &books[i].price) == 1)
				printf("Book details updated successfully!\n");
			return;
		}
	}
	printf("Book not found!\n");
}

void countBooks(void)
{
	printf("Total Books: %d\n", count);
}

void availableBooks(void)
{
	int found = 0;
	printf("\nAvailable Books:\n");
	for (int i = 0; i < count; i++)
	{
		if (!books[i].issued)
		{
			printf("\nBook ID: %d", books[i].id);
			printf("\nBook Name: %s\n", books[i].name);
			found = 1;
		}
	}
	if (!found)
		printf("No available books!\n");
}

int main(void)
{
	int choice;
	do
	{
		printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
		printf("\n1. Add New Book");
		printf("\n2. Display All Books");
		printf("\n3. Search Book by ID");
		printf("\n4. Search Book by Name");
		printf("\n5. Issue Book");
		printf("\n6. Return Book");
		printf("\n7. Update Book Details");
		printf("\n8. Count Total Books");
		printf("\n9. Display Available Books");
		printf("\n10. Exit");
		printf("\n\nEnter your choice: ");
		if (scanf("%d", &choice) != 1)
			return 1;

		switch (choice)
		{
			case 1: addBook(); break;
			case 2: displayBooks(); break;
			case 3: searchByID(); break;
			case 4: searchByName(); break;
			case 5: issueBook(); break;
			case 6: returnBook(); break;
			case 7: updateBook(); break;
			case 8: countBooks(); break;
			case 9: availableBooks(); break;
			case 10: printf("Thank you for using Library Management System!\n"); break;
			default: printf("Invalid choice! Please try again.\n");
		}
	} while (choice != 10);

	return 0;
}