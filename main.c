#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	if (argc!=3){
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin b.bin\n");
		printf("please select two files.\n");
		return 1;
	}

	uint32_t x,y,res1,res2;
	FILE *fp1,*fp2;

	fp1=fopen(argv[1], "rb");
	fp2=fopen(argv[2],"rb");

	if(res1!=1||res2!=1){
		printf("Files cannot be read.\n");
		return 1;
	}

	res1=fread(&x,sizeof(uint32_t),1,fp1);
	res2=fread(&y,sizeof(uint32_t),1,fp2);

	if(fp1==NULL||fp2==NULL){
		printf("Files cannot be opened.\n");
		return 1;
	}
	x=ntohl(x);
	y=ntohl(y);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", x, x, y, y, x+y, x+y);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
//파일이 제대로 열리지 않는 경우, 파일의 크기가 4바이트보다 작아서 제대로 읽지 못했다고 판단되는 경우 