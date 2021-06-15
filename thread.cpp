#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

void func_long(double& res){
    double sum = 0;
    cout << "Start long" << endl;
    for( auto i=0; i<200'000; i++){
        for(auto j=0; j<15'000; j++){
            sum += i / (j+1);
        }
    }
    res = 12345;
    cout << "End long" << endl;
}

static void func2(int start){
    for(int i=0; i<10; i++){
        cout << "Cpt func 2 : " << start + i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void func4(int start, int id, mutex& m){
    //m.lock(); // aucun intérêt on casse le //
    for(int i=0; i<100; i++){
        m.lock();
        cout << "Cpt func 4 : " << endl;
        cout << "  - id : " << id << endl;
        cout << "  - cpt : " << start + i << endl;
        m.unlock();
    }
    //m.unlock();
}

void test_thread(){
    cout << "Start test thread" << endl;

    double res1, res2;

    //thread t1(func_long, ref(res1) );    
    //thread t2(func_long, ref(res2) );
    //t1.join();
    //t2.join();

    //func_long(res1);
    //func_long(res2);
    //cout << "res 1 : " << res1 << endl;
    //cout << "res 2 : " << res2 << endl;

    //func2(0);
    //func2(10);
    mutex m;
    thread t1(func4, 0, 1, ref(m));
    thread t2(func4, 10, 2, ref(m));
    t1.join();
    t2.join();
}