#include <iostream>

using namespace std;

// 1) R+B = L*W로 해서 돌릴까 했는데 > 1억 이므로 브루트포스 불가..
/* 2) B를 구하면 전체에서 뺴면 R이 나오므로 B를 타겟
      B는 L-2 * W-2 인데.. 
      1. 최소 열 3이상
      2. 행과 열의 차이가 최소인 조합
*/ 

int main(){

    int r,b,R,B;
    cin >> r >> b; 

    int square = r+b;

    for(int W=3;W<=square;W++){
    	int L = square/W;  // 1) 나누어 떨어지지 않을 때(정수가 아닐 경우)를 고려할까 했지만... 
		
	    B = (W-2)*(L-2);
	    R = square-b;
	
	    if(r==R && b==B){ // 2) 여기서 2가지 모두를 검사하고 + int형이므로 애초에 square 조건에 맞지 않을 것같아 생략
	        cout << L << " " << W << '\n';
	        break;
	    }
    }
    
    return 0;
} // -> 그런데 시간초과 나왔습니다.. ㅠㅠ 다시 어떤 식으로 시도해보는 게 좋을까요?


/*int square(int r, int b){
    int sum = r+b;

    for(int i=2;i*i<=sum;i++){
        while(sum%i==0){
            int count++;
            sum/=i;
        }
    }

}

int main(){
    int r,b;
    // 입력
    cin >> r >> b; 

    // 출력
    cout << << endl;

    return 0;
}*/ 
