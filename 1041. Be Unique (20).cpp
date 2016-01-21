#include <cstdio>
int main()
{
	int a[100005] = {0};
	int h[100005] = { 0 };
	int b,c,d;
	scanf("%d",&b);
	d = -1;
	for (int i = 0; i < b && (scanf("%d", &c)); i++) {
		if (a[c] != 0)
			a[c] = -1;
		else
			a[c] = c;
		h[i] = c;
	}
	for (int i = 0; i < b; i++)
	{
		if (a[h[i]] >0) {
			d = a[h[i]];
			break;
		}
	}
	if (d == -1)
		printf("None");
	else
		printf("%d",d);

	return 0;
}