struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
        int id;
        struct newNodeFB *next;
};

void insertFB(struct nodeFB ** r, int id, int age)
{
        struct nodeFB *temp = (struct nodeFB*)malloc(sizeof(struct nodeFB));
        if((*r) == NULL)  //Linked listin boş olma durumu.
        {
        	temp -> next = NULL;
        	temp -> id = id;
        	temp -> age = age;
		(*r) = temp; 
        	return; //İşlem sonunda fonksiyondan çıkış.
    	}
    	if((*r) -> id > id) //Eklenen ilk elemanın rootdan küçük olma durumu.
    	{
        	temp -> next= (*r);
        	temp -> id = id;
        	temp -> age = age;
		(*r) = temp; 
        	return;  //İşlem sonunda fonksiyondan çıkış.
    	}

    	struct nodeFB* progress;
    	progress = (*r);
    	while(progress -> next != NULL && progress -> next-> id < id)  //Arada veya sonda bir ekleme yapma durumu.
    	{
        	progress = progress -> next;
    	}
    	temp -> next = progress -> next;
    	progress -> next = temp;
    	temp -> id = id;
    	temp -> age = age;
}

void insertGS(struct nodeGS** r, int id)
{
        struct nodeGS *temp = (struct nodeGS*)malloc(sizeof(struct nodeGS));
    	if((*r) == NULL)  //Linked listin boş olma durumu.
    	{
        	temp -> next = NULL;
        	temp -> id = id;
		(*r) = temp; 
        	return;  //İşlem sonunda fonksiyondan çıkış.
    	}
    	if((*r) -> id < id) //Eklenen ilk elemanın rootdan küçük olma durumu.
    	{
        	temp -> next = (*r);
        	temp -> id = id;
		(*r) = temp; 
        	return;  //İşlem sonunda fonksiyondan çıkış.
    	}

    	struct nodeGS * progress;
    	progress = (*r);
    	while(progress -> next != NULL && progress -> next -> id > id)  //Arada veya sonda bir ekleme yapma durumu.
    	{
        	progress = progress -> next;
    	}
    	temp -> next = progress ->next;
    	progress -> next = temp;
   	temp-> id = id;
	}

void printFB(struct nodeFB* r)
{
 	struct nodeFB * start = (struct nodeFB*)malloc(sizeof(struct nodeFB));   	
	start = r;
	while(start != NULL)
	{
		printf("%d %d\n" , start -> id , start -> age);
		start = start -> next;
	}
	printf("\n");
}

void printGS(struct nodeGS* r)
{
	struct nodeGS * start = (struct nodeGS*)malloc(sizeof(struct nodeGS));     	
	start = r;
	while(start != NULL)
	{
		printf("%d\n" , start -> id);
		start = start -> next;
	}
	printf("\n");
}

void createFinalList(struct newNodeFB** startNewFB, struct nodeFB* startFB, struct nodeGS* startGS)
{
 	struct newNodeFB * fenb = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
 	if((*startNewFB) == NULL)
 	{
     		(*startNewFB) = fenb;
 	}

 	while(startFB != NULL || startGS != NULL)
 	{
     		struct newNodeGS* gals = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
     		fenb -> id = startFB -> id;
     		fenb -> age = startFB -> age;
     		fenb -> next = gals;

     		gals -> id = startGS -> id;
     		fenb = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
     		gals -> next = fenb;
     		startGS = startGS -> next;
     		startFB = startFB -> next;
	}
}

void printAll(struct newNodeFB *startNewFB) {
    	struct newNodeFB* ptrFB = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
    	struct newNodeGS* ptrGS = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
	ptrFB = startNewFB;
    	while(ptrFB -> next != NULL)
    	{
        	printf("%d %d\n", ptrFB -> id , ptrFB -> age);
        	ptrGS = ptrFB -> next;
        	printf("%d\n", ptrGS -> id);
        	ptrFB = ptrGS -> next;
    	}
}

