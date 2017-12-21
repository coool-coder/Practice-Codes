// hello! brother, how are you? -> !olleh ,rehtorb woh era ?uoy

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse(char *sent){
	int len = strlen(sent);
	char *ReverseStr = (char*)malloc((len+1)*sizeof(char)); 
	int st = 0;
	int count = 0;
	for(int i = 0; i < len; i++){
		count = 0;
		while(sent[i] != ' ' && sent[i] != '\n' && sent[i] != '\0'){
			count++;
			i++;
		}
		int j;
		for (j = st; j < st + count; j++){
			ReverseStr[j] = sent[--i];
			// printf("%c %c\n", ReverseStr[j], sent[i]);
		}
		st = st + count + 1;
		ReverseStr[j++]=' ';
		i+=count;
	}
	return ReverseStr;
}

int main(){
	char sent[1000];
	scanf("%[^\n]s", sent);

	char *str = reverse(sent);
	printf("String with words in reversed order: %s\n", str);

	return 0;
}