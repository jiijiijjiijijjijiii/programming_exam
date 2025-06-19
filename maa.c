#include <stdio.h>

int t, i, j, k, enc_ascii, enc_i;
char key;
char text_1[100], text_2[100], disk[100];
char text[100] = "I LOVE YOU AND YOU TOO";
char keytable[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S',
        'T', 'U', 'V', 'W', 'X', 'Y', 'Z', };

char makeDisk(char key){

    for(i = 0; i <= 25; i++){ // k값을 정하는 코드, k 값은 keytable안에 key값에 해당하는 인덱스 번호
        if(key == keytable[i]){ 
            k = i;    
        }
    }

    for(j = 0; j <= 25; j++){ // disk배열 생성 코드, 암호화 키 값
     
        enc_i = (j + k) % 26;
        enc_ascii = enc_i + 65;
        disk[j] = enc_ascii;
    }
    return printf("암호화 키 : %s\n", disk);
}

char caesar(char msg[], int a){

    
    for(int q = 0; q <= 50; q++){
        for(int p = 0; p <= 50; p++){
        
            if(a == 0){    
                if(msg[q] == keytable[p]){    // 암호화 하는 코드
                    text_1[q] = disk[p];
                }
                else if(msg[q] == ' '){
                    text_1[q] = ' ';
                }
                
            }
            if(a == 1){    
                if(msg[q] == disk[p]){    // 복호화 하는 코드
                    text_2[q] = keytable[p];    
                }
                else if(msg[q] == ' '){
                    text_2[q] = ' ';
                }
                
            }
        }
    }
    
    return printf("완료\n");

}

int main(){

    scanf("%c", &key);   // key 값 지정
    
    char a[100];
    char b[100];
    
    makeDisk(key);

    caesar(text, 0);
    caesar(text_1, 1);

    for(int y = 0; y <= 30; y++){
    
        a[y] = text_1[y];    // 암호화된 문장을 a배열 안에 저장
        b[y] = text_2[y];    // 복호화된 문장을 b배열 안에 저장
    }

    printf("원래 문장 : %s\n", text);
    printf("암호화된 문장 : %s\n", a);
    printf("복호화된 문장 : %s\n", b);
    
    return 0;

}
