#include <stdio.h>
#define MAX 2000
int get_line(char s[]);
void escape(char s[], char t[]);

int main(void)
{
	char s[MAX], t[MAX];
	int len;

	while ((len = get_line(s)) != 0)
	{
		escape(s, t);
		printf("Result in usage of switch: %s\n", t);
	}
	return 0;
}

int get_line(char s[])
{
	int i, c;

	for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}

	if (c == '\n')
	{
		s[i++] = c;
	}

	s[i] = '\0';
	return i;
}

void escape(char s[], char t[])
{
	int i, j;
	j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (j < MAX-2)
		{
			switch (s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			default:
				t[j++] = s[i];
				break;
			}
		}
	}
	t[j] = '\0';
}
