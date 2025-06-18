#include <stdio.h>

int t, i, j, k, enc_ascii, enc_i, Enc = 0, Dec = 1;
char key, m;
char text_1[50], text_2[50];
//char text_2[50];
char text[50] = "I LOVE YOU AND YOU TOO";
char enc_disk[100];
char keytable[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S',
        'T', 'U', 'V', 'W', 'X', 'Y', 'Z', };

char makeDisk(char key){

    for(i = 0; i <= 25; i++){
        if(key == keytable[i]){
            k = i;    
        }
    }

    for(j = 0; j <= 25; j++){
     
        enc_i = (j + k) % 26;
        enc_ascii = enc_i + 65;
        m = enc_ascii;
        enc_disk[j] = m;
    }
    
}

char caesar(char msg[], int a){

    
    for(int q = 0; q <= 50; q++){
        for(int p = 0; p <= 50; p++){
            if(a == Enc){

                if(msg[q] == keytable[p]){
                    text_1[q] = enc_disk[p];
                }
                else if(msg[q] == ' '){
                    text_1[q] = ' ';
                }
            
            }
            if(a == Dec){
                if(msg[q] == enc_disk[p]){
                    text_2[q] = keytable[p];    
                }
                else if(msg[q] == ' '){
                    text_2[q] = ' ';
                }
            }
        }
    }

    

}

int main(){

    key = 'F';
    char a[50];
    char b[50];
    
    makeDisk(key);

    caesar(text, Enc);
    caesar(text_1, Dec);

    for(int y = 0; y <= 30; y++){
    
        a[y] = text_1[y];
        b[y] = text_2[y];
    }

    printf("원래 문장 : %s\n", text);
    printf("암호화된 문장 : %s\n", a);
    printf("복호화된 문장 : %s\n", b);
    
    return 0;

}