#include <iostream>
#include <stack>
#include <vector>

using namespace std; 

// idea : �հ����� ���� ���� �����̴� Ƚ�� = �ּҰ���� <- �ִ����� �̿� 
// + ���� ���� �͸� ����Ѵٴ� ��..  

/**
 * �� �ٸ��� �ܰ����� ������ �ִ� ������ ���ÿ� �����ϱ�
 * �� �Է¿� ���� �̹��� ���� ������ �ش� �ٿ��� ���� ���� �����̾�� ��
 *
 * 1. �̹��� ������ �� �������� ���� �������� �հ����� ���� ����
 * 2. ���� �̹��� ������ �� ������ ������ ���� �ʴٸ� ������
 */
 
int main() {
    int n, p, guitar_string, fret, ans = 0; // Ƚ���� �������� ���� ans  

    cin >> n >> p;
    vector<stack<int>> guitar(7); //1�� �ٺ��� 6���� ����
    while (n--) {
        //�Է�
        cin >> guitar_string >> fret;

        //����
        while (!guitar[guitar_string].empty() && guitar[guitar_string].top() > fret) { //�������� �հ��� ���� - ��������
            ans++; // Ƚ�� ����  
            guitar[guitar_string].pop(); // ���� ���� �� + top�� �������� ũ�� ���� ū ���� �����Ƿ� pop���ִ� ��  
        }
        if (guitar[guitar_string].empty() || guitar[guitar_string].top() != fret) { //���� ������
            ans++; // Ƚ�� ���� 
            guitar[guitar_string].push(fret); ////  �����  �� or top�� ����
        }
    }

    //���
    cout << ans;
}
