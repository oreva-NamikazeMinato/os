#include <stdio.h>

struct process
{
    int size, flag, holeid;
};

struct hole
{
    int hid, size, actual;
};

void bestFit(struct process[], int, struct hole[], int);

int main()
{
    struct process p[10];
    struct hole h[10];
    int i, np, nh;

    printf("Enter the number of Holes: ");
    scanf("%d", &nh);

    for (i = 0; i < nh; i++)
    {
        printf("Enter size for hole H%d: ", i);
        scanf("%d", &h[i].size);
        h[i].actual = h[i].size;
        h[i].hid = i;
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++)
    {
        printf("Enter the size of process P%d: ", i);
        scanf("%d", &p[i].size);
        p[i].flag = 0;
    }

    bestFit(p, np, h, nh);

    printf("\n\tBest Fit\n");
    printf("\nProcess\tPSize\tHole");

    for (i = 0; i < np; i++)
    {
        if (p[i].flag != 1)
            printf("\nP%d\t%d\tNot allocated", i, p[i].size);
        else
            printf("\nP%d\t%d\tH%d", i, p[i].size, p[i].holeid);
    }

    printf("\n\nHole\tActual\tAvailable");

    for (i = 0; i < nh; i++)
        printf("\nH%d\t%d\t%d", h[i].hid, h[i].actual, h[i].size);

    printf("\n");

    return 0;
}

void bestFit(struct process p[], int np, struct hole h[], int nh)
{
    int i, j;

    for (i = 0; i < np; i++)
    {
        int bestFitIdx = -1;
        for (j = 0; j < nh; j++)
        {
            if (p[i].size <= h[j].size)
            {
                if (bestFitIdx == -1 || h[j].size < h[bestFitIdx].size)
                {
                    bestFitIdx = j;
                }
            }
        }

        if (bestFitIdx != -1)
        {
            p[i].flag = 1;
            p[i].holeid = h[bestFitIdx].hid;
            h[bestFitIdx].size -= p[i].size;
        }
    }
}
