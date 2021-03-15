
#include <stdio.h>
int main()
{
    printf("Entrez une valeur pour calculer sa factorielle: ");
    int n;
    scanf("%d", &n);
    int factorielle; 
    for (int i =0; i <n ; i++){
        factorielle *= (2*n+1);
    }

    printf("La factorielle impaire de %n est %\n", n);
    return 0;
}