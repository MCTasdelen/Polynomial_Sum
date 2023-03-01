
#include <stdio.h>
#include <stdlib.h>

typedef struct poly_node* poly_pointer;
typedef struct poly_node {
	int coefficient;
	int expon;
	poly_pointer next;
};
poly_pointer a, b, d;




struct poly_node* insert(int exp, int coef, struct poly_node* head)
{
	struct poly_node* temp;
	temp = malloc(sizeof(struct poly_node));
	temp->coefficient = coef;
	temp->expon = exp;
	temp->next = head;
	head = temp;
}
void Print(struct poly_node* head)
{
	struct poly_node* temp = head;
	while (temp != NULL)
	{
		printf("%d\t%d\n", temp->coefficient, temp->expon);
		temp = temp->next;
	}
}
struct poly_node* Reverse(struct poly_node* head)
{
	struct poly_node* temp;
	struct poly_node* prev = NULL;
	struct poly_node* p = head;
	while (p)
	{
		temp = p->next;
		p->next = prev;
		prev = p;
		p = temp;

	}
	head = prev;
}
struct poly_node* polynomials()
{


	while (a && b)
	{
		if (a->expon == b->expon) {
			if ((a->coefficient + b->coefficient)) {
				d = insert(a->expon, (a->coefficient + b->coefficient), d);
			}
			a = a->next;
			b = b->next;

		}
		else if (a->expon > b->expon)
		{
			d = insert(a->expon, a->coefficient, d);
			a = a->next;

		}
		else if (a->expon < b->expon)
		{
			d = insert(b->expon, b->coefficient, d);
			b = b->next;
		}

	}
	if (a != NULL)
	{
		while (a)
		{
			d = insert(a->expon, a->coefficient, d);
			a = a->next;

		}
	}
	else if (b != NULL)
	{
		d = insert(b->expon, b->coefficient, d);
		b = b->next;
	}


}
int main()
{
	a = NULL, b = NULL, d = NULL;
	a = insert(0, 1, a);
	a = insert(8, 2, a);
	a = insert(14, 3, a);
	b = insert(6, 10, b);
	b = insert(10, 3, b);
	b = insert(14, 8, b);

	printf("List a:\n");
	Print(a);
	printf("List b:\n");
	Print(b);
	printf("List d:\n");
	polynomials();
	d = Reverse(d);
	Print(d);
}