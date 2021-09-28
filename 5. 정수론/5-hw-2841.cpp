#include <iostream>
#include <stack>
#include <vector>

using namespace std; 

// idea : 손가락이 가장 적게 움직이는 횟수 = 최소공배수 <- 최대공약수 이용 
// + 가장 높은 것만 계산한다는 것..  

/**
 * 각 줄마다 외계인이 누르고 있는 프렛을 스택에 저장하기
 * 매 입력에 대해 이번에 누를 프렛이 해당 줄에서 가장 높은 프렛이어야 함
 *
 * 1. 이번에 눌러야 할 프렛보다 높은 프렛에서 손가락을 전부 떼기
 * 2. 만약 이번에 눌러야 할 프렛을 누르고 있지 않다면 누르기
 */
 
int main() {
    int n, p, guitar_string, fret, ans = 0; // 횟수를 세기위한 변수 ans  

    cin >> n >> p;
    vector<stack<int>> guitar(7); //1번 줄부터 6번줄 까지
    while (n--) {
        //입력
        cin >> guitar_string >> fret;

        //연산
        while (!guitar[guitar_string].empty() && guitar[guitar_string].top() > fret) { //프렛에서 손가락 떼기 - 종료조건
            ans++; // 횟수 세기  
            guitar[guitar_string].pop(); // 비지 않을 때 + top이 프렛보다 크면 가장 큰 것이 찍히므로 pop해주는 것  
        }
        if (guitar[guitar_string].empty() || guitar[guitar_string].top() != fret) { //프렛 누르기
            ans++; // 횟수 세기 
            guitar[guitar_string].push(fret); ////  비었을  때 or top이 프렛
        }
    }

    //출력
    cout << ans;
}
