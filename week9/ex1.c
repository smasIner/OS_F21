#include <stdio.h>
#include <stdlib.h>

#define FRAMEMAXNUM 10000
#define INT16_MAX   32767

struct pageFrame{
    int pageContained;
    int empty; // boolean
};
struct page{
    int numberOfPage;
    unsigned char softwareCounter; // unsigned char is 8 bit in c
    int rBit;
    int presentInFrame; // boolean
};
struct inputProxy{
    int clockCycle;
    int numberOfPageAccessed;
};

void sortInput(struct inputProxy *input, int n){
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (input[j].clockCycle > input[j + 1].clockCycle){
                struct inputProxy temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

void preparePages(struct page *pages){
    for (int i = 0; i < FRAMEMAXNUM; ++i) {
        pages[i].rBit = 0;
        pages[i].softwareCounter = 0;
        pages[i].numberOfPage = i;
        pages[i].presentInFrame = 0; // false
    }
}
void preparePageFrames(struct pageFrame *pageFrames, int n){
    for (int i = 0; i < n; ++i) {
        pageFrames[i].pageContained = -1;
        pageFrames[i].empty = 1; // true
    }
}
void tryPush( struct pageFrame pageFrames[], struct page *pages, int numOfPageFrames);
void deletionProcess(struct pageFrame pageFrames[], struct page *pages, int numOfPageFrames){
    int minVal = INT16_MAX;
    int counter = 0;
    int pagesNum = -1;
    int frameNum = -1;
    int temp = pages->numberOfPage;
    for (int i = 0; i < numOfPageFrames; ++i) {
        if(pages[pageFrames[i].pageContained - temp].softwareCounter <= minVal){
            if(pages[pageFrames[i].pageContained - temp].softwareCounter == minVal){
                if(pages[pageFrames[i].pageContained - temp].numberOfPage < pages[pagesNum].numberOfPage){
                    pagesNum = pageFrames[i].pageContained - temp;
                    frameNum = i;
                    continue;
                }
                else{
                    continue;
                }
            }
            minVal = pages[pageFrames[i].pageContained - temp].softwareCounter;
            pagesNum = pageFrames[i].pageContained - temp;
            frameNum = i;

        }
    }
    pages[pagesNum].softwareCounter = 0;
    pages[pagesNum].rBit = 0;
    pages[pagesNum].presentInFrame = 0;
    pageFrames[frameNum].pageContained = -1;
    pageFrames[frameNum].empty = 1;
    /*
    for (int i = 0; i < numOfPageFrames; ++i) {
        if(pages[pageFrames[i].pageContained - temp].softwareCounter == minVal){
            pages[pageFrames[i].pageContained - temp].softwareCounter = 0;
            pages[pageFrames[i].pageContained - temp].rBit = 0;
            pages[pageFrames[i].pageContained - temp].presentInFrame = 0;
            pageFrames[i].pageContained = -1;
            pageFrames[i].empty = 1;
            break;
        }
    }
     */
    tryPush(pageFrames, pages, numOfPageFrames);
}

void tryPush( struct pageFrame pageFrames[], struct page *pages, int numOfPageFrames){
    for (int i = 0; i < numOfPageFrames; ++i) {
        if(pageFrames[i].empty){
            pageFrames[i].empty = 0;
            pageFrames[i].pageContained = pages->numberOfPage;
            pages->presentInFrame = 1;// true
            break;
        }
        else if (i == numOfPageFrames - 1){
            deletionProcess(pageFrames, pages, numOfPageFrames);
        }
    }
};

int main() {
    int numOfPageFrames = 0;
    int numOfMemoryAccesses = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &numOfPageFrames);
    printf("\n");
    printf("Enter the number of memory Accesses: ");
    scanf("%d", &numOfMemoryAccesses);
    printf("\n");
    struct page pages[FRAMEMAXNUM];
    struct inputProxy input[numOfMemoryAccesses];
    struct pageFrame pageFrames[numOfPageFrames];

    preparePages(pages);
    preparePageFrames(pageFrames, numOfPageFrames);

    
    int hits = 0;
    int misses = 0;
    printf("Enter the memory accesses in format: (int number of cycle) (int page accessed), as eg: \n 5 2\n");
    for (int i = 0; i < numOfMemoryAccesses ; ++i) {
        scanf("%d %d", &input[i].clockCycle, &input[i].numberOfPageAccessed);
    }

    // sortInput(input, numOfMemoryAccesses);

    // do the processing of the memory accesses
    int newCycle = input->clockCycle;
    for (int i = 0; i < numOfMemoryAccesses; ++i) {
        if(newCycle == input[i].clockCycle){
            int pageNum = input[i].numberOfPageAccessed - 1;
            pages[pageNum].rBit = 1;
            pages[pageNum].softwareCounter = (pages[pageNum].softwareCounter>>1) | (pages[pageNum].rBit << 7);
            if(pages[pageNum].presentInFrame){
                printf("1\n");
                hits++;
                continue;
            }
            else{
                printf("0\n");
                tryPush(pageFrames, &pages[pageNum], numOfPageFrames);
            }
        }
        else{
            for (int j = 0; j < numOfPageFrames; ++j) {
                int temp = -1;
                if(pageFrames[j].pageContained != - 1){
                    temp = pageFrames[j].pageContained;
                }
                else{
                    continue;
                }
                if(pages[temp].rBit == 0) {
                    pages[temp].softwareCounter = (pages[temp].softwareCounter >> 1) | (pages[temp].rBit << 7);
                }
                pages[temp].rBit = 0;
            }
            newCycle = input[i].clockCycle;
            i--;
        }
    }

    misses = numOfMemoryAccesses - hits;
    if(hits + misses != 0) {
        printf("Hit ratio is: %lf\n", (double) hits / (misses + hits));
        printf("Miss ratio is: %lf\n", (double) misses / (misses + hits));
        printf("Hits/misses (parameter from stepik): %lf",(double) hits / (double) misses);
    }
    else{
        printf("Error: 0 misses, 0 hits");
        exit(1);
    }
    return 0;
}
