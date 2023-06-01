#include <stdio.h>
#define L3 3
#define P2 2
int main(){
    int L1, L2, P1;
    int pageSize;
    int ofsetSize;
    printf("Enter the page size: ");
    scanf("%d", &pageSize);
    printf("\nEnter the of-set size: ");
    scanf("%d", &ofsetSize);
    L1 = P1 = pageSize;
    L2 = ofsetSize;
    int i, j, k;
    int logicalMemory[L1][L2][L3];
    printf("Getting logical table data");
    for ( i = 0; i < L1; i++){
        for ( j = 0; j < L2; j++){
            for ( k = 0; k < L3; k++){
                if(k == 0){
                    logicalMemory[i][j][k] = i;
                }
                else if(k == 1){
                    printf("\nEnter address and page number: ");
                    scanf("%d", &logicalMemory[i][j][k]);
                }else if(k == 2){
                    scanf("%d", &logicalMemory[i][j][k]);
                }
            }
        }
    }
    int pageTable[P1][P2];
    printf("\nGetting page table data\n");
    for ( i = 0; i < P1; i++){
        for ( j = 0; j < P2; j++){
            if(j==0){
                printf("Enter page number and frame number: ");
                scanf("%d", &pageTable[i][j]);
            }else if (j==1){
                scanf("%d", &pageTable[i][j]);
            }
        }
    }
    printf("\nLogical memory:\n");
    printf("\nPage number\tAddress\t\tData\n");
    for ( i = 0; i < L1; i++){
        for ( j = 0; j < L2; j++){
            for ( k = 0; k < L3; k++){
                printf("%d\t\t", logicalMemory[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\nPage table:\n");
    printf("\nPage number\tFrame Number\n");
    for ( i = 0; i < P1; i++){
        for ( j = 0; j < P2; j++){
            printf("%d\t\t", pageTable[i][j]);
        }
        printf("\n");
    }
    int sValue, pageNumber, frameNumber, ofsetIndexNumber;
    printf("\nEnter the value that you want to find the address: ");
    scanf("%d", &sValue);
    for ( i = 0; i < L1; i++){
        for ( j = 0; j < L2; j++){
            if (logicalMemory[i][j][2] == sValue){
                pageNumber = i;
                ofsetIndexNumber = j;
                break;
            }
        }
    }
    for ( i = 0; i < P1; i++){
        if(pageTable[i][0] == pageNumber){
            frameNumber = pageTable[i][1];
            break;
        }
    }
    printf("\nPage number: %d", pageNumber);
    printf("\nFrame number: %d", frameNumber);
    printf("\nOf-set index number: %d", ofsetIndexNumber);
    int physicalMemoryAddress;
    physicalMemoryAddress = frameNumber * L2 + ofsetIndexNumber;
    printf("\n\n%d * %d + %d = %d", frameNumber, L2, ofsetIndexNumber, physicalMemoryAddress);
    printf("\n\nPhysical Memory Address = %d\n\n", physicalMemoryAddress);
    return 0;
}
