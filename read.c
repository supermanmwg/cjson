#include <stdio.h>
#include "cJSON.h"
#include <assert.h>

static char read_buf[1024];
void main() {
	FILE *fp;

	fp = fopen("./test.txt", "r");
	if(NULL == fp) {
		printf("the file can't be opened!\n");
	} else {
		printf("the file is opened!\n");
	}
	assert(NULL != fp);

	int n = fread(read_buf, sizeof(char), 1024, fp);

	printf("read %d characters\n", n);

	printf("characters is %s\n", read_buf);

	cJSON *name = NULL;
	cJSON *index = NULL;
	cJSON *optional = NULL;

	cJSON *request_json = cJSON_Parse(read_buf);
	cJSON *item = cJSON_GetObjectItem(request_json, "items");	
	printf("Json array size is %d\n", cJSON_GetArraySize(item));
	int i = 0;
 	for (i = 0 ; i < cJSON_GetArraySize(item) ; i++) {
     	cJSON * subitem = cJSON_GetArrayItem(item, i);
     	name = cJSON_GetObjectItem(subitem, "name");
     	index = cJSON_GetObjectItem(subitem, "index");
     	optional = cJSON_GetObjectItem(subitem, "optional"); 
		printf("name is %s\n", name->valuestring);
		printf("index is %s\n", index->valuestring);
		printf("optional is %s\n", optional->valuestring);
  	}

}
