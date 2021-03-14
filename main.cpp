#include <iostream>
using namespace std;

struct Coada{
    int q[1000];
    int lungime = 0;

    void addInQueue(int x){
        q[lungime++] = x;
    }

    int removeFromQueue(){
        int x = q[0];
        for(int i = 0; i < lungime - 1; i++)
            q[i] = q[i+1];
        lungime--;
        return x;
    }
};

struct Stiva{
    Coada q1, q2;
    int lungime = 0;
    // Cand adaug in stiva voi pune toate elementele in q1
 
    void addInStack(int x){
        q1.addInQueue(x);
    }

    // folosesc q2 ca un intermediar (auxiliar) ca sa ajung la elemtul cautat
    void removeFromStack(){
        if (q1.lungime == 0){
            cout << "Stiva este goala" << endl;
            return;
        }
        // pun in q2 toate elementele mai putin pe ultimul (pentru ca acela este elemul care trebuie eliminat)
        while(q1.lungime > 1){
            q2.addInQueue(q1.removeFromQueue());
        }

        int x = q1.removeFromQueue();
        // adaug in q1 celelalte elemete ramase
        while(q2.lungime > 0){
            q1.addInQueue(q2.removeFromQueue());
        }
        // cout << x;
    }

    void printS(){  
        for (int i = 0; i < q1.lungime; i++)
            cout << q1.q[i] << " ";
    }

};



int main(){
    Stiva s;
    s.removeFromStack();
    s.addInStack(1);
    s.addInStack(8);
    s.addInStack(5);
    s.addInStack(9);
    s.printS();
    s.removeFromStack();
    cout << endl;
    s.printS();
    return 0;
}