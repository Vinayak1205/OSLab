#include <stdio.h>


struct Blocks{
    int bno,bsize,is_free;
};

struct Files{

    int fno,fsize;
};

int tbsize = 0;
void best_fit(struct Blocks blocks[],struct Files files[],int b,int f){

    printf("\nBest fit Algo: ");
    printf("\nbno\tbsize\tfno\tfize\tfragment");
    for(int i=0; i<f; i++){

        int mini = 100000,bfitblock = -1;
        for(int j=0; j<b; j++){

            if(blocks[j].bsize >= files[i].fsize){
                int fragment = blocks[j].bsize - files[i].fsize;
                if(fragment < mini){
                    mini = fragment;
                    bfitblock = j;
                }
            }
        }

        if(bfitblock != -1){

            printf("\n%d\t%d\t%d\t%d\t%d",blocks[bfitblock].bno,blocks[bfitblock].bsize,files[i].fno,files[i].fsize,mini);
            blocks[bfitblock].is_free = 0;
            tbsize -= mini;
        }
        else
            printf("\nBlock not allocated");
    }

    printf("\nRemaining Blocks Size: %d",tbsize);

}

int main(){

    int f,b;

    printf("\nEnter the no of files and no of blocks: ");
    scanf("%d%d",&f,&b);

    struct Blocks blocks[b];
    struct Files files[f];



    printf("\nEnter Blocks Data: ");
    for(int i=0; i<b; i++){

        blocks[i].bno = i+1;
        printf("\nEnter block size for %d block: ",i+1);
        scanf("%d",&blocks[i].bsize);
        blocks[i].is_free = 1;
        tbsize += blocks[i].bsize;

    }


    printf("%d",tbsize);
    printf("\nEnter Files Data: ");
    for(int i=0; i<f; i++){

        files[i].fno = i+1;
        printf("\nEnter file size for %d file: ",i+1);
        scanf("%d",&files[i].fsize);

    }

    printf("\nBlock Size: %d",tbsize);
    best_fit(blocks,files,b,f);

    return 0;
}

