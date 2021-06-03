#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct for planet data
struct planet
{
    char name[30];
    float size;
};

void writep() //to write data in file
{
	FILE *file;
	file=fopen("planets.txt", "a+");
	if (file == NULL)
    {
        printf( "\nError opened file\n");
        exit (1);
    }
    struct planet p;
    printf("Enter Planet Name and Planet Size:");
    scanf("%s", &p.name);
    scanf("%f", &p.size);

	fwrite (&p, sizeof(struct planet), 1, file);
    fclose (file);
}
void readp() //to read all entries in text file
{
	FILE *file;
	file=fopen("planets.txt", "r");
	if (file == NULL)
    {
        printf( "\nError opend file\n");
        exit (1);
    }
    struct planet p;
    printf( "\nContent of file\n");
    while(fread(&p, sizeof(struct planet), 1,file))
    {
        printf ("Name = %s Size = %f\n", p.name, p.size);
    }
    fclose(file);
}
void largesize() //to find the planet with largest size
{
    FILE *file;
	file=fopen("planets.txt", "r");
	if (file == NULL)
    {
        printf( "\nError opend file\n");
        exit (1);
    }
    struct planet p, r;
    float m=-1.0;
    while(fread(&p, sizeof(struct planet), 1,file))
    {
        if(m<p.size)
        {
            m=r.size=p.size;
            strcpy(r.name, p.name);
        }
    }
    printf ("\n\nPlanet with Largest Size\nName = %s Size = %f\n", r.name, r.size);
    fclose(file);
}
void letter(char c) //to find the all planet details that begin with
{                   // letter  prompted by the user
    c=tolower(c);

    FILE *file;
    char s[30];
	file=fopen("planets.txt", "r");
	if (file == NULL)
    {
        printf( "\nError opend file\n");
        exit (1);
    }
    struct planet p;
    while(fread(&p, sizeof(struct planet), 1,file))
    {
        strcpy(s, p.name);
        s[0]=tolower(s[0]);
        if(s[0]==c)
        printf ("\nName = %s Size = %f\n", p.name, p.size);
    }
    fclose(file);

}
int main() {

	char c;
	char ans='y';
	while(ans=='y' || ans=='Y')
	{
	    writep();
	    printf("DO YOU WISH TO ADD MORE ENTRIES: ");
        scanf("%s", &ans);
	}

	readp();
	largesize();
	ans='y';

	while(ans=='y' || ans=='Y')
	{
	    printf("Enter Letter: ");
        scanf("%s", &c);
        letter(c);
	    printf("DO YOU WISH TO PRINT MORE ENTRIES: ");
        scanf("%s", &ans);
	}
	return 0;
}
