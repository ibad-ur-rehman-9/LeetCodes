

class Foo {
pthread_mutex_t mt ;
pthread_cond_t cv ;
int turn = 0;

public:
    Foo() {
        turn =0;
        pthread_mutex_init(&mt, NULL);
pthread_cond_init(&cv, NULL);

    }

    void first(function<void()> printFirst) {
        pthread_mutex_lock(&mt);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1;
        pthread_cond_broadcast(&cv);

        pthread_mutex_unlock(&mt);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        pthread_mutex_lock(&mt);
        while(turn != 1)
        {
            pthread_cond_wait(&cv, &mt);
        }
        
        printSecond();
        turn = 2;
        pthread_cond_broadcast(&cv);

        pthread_mutex_unlock(&mt);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        pthread_mutex_lock(&mt);
        while(turn != 2)
        {
             pthread_cond_wait(&cv, &mt);
        }
        printThird();
        pthread_mutex_unlock(&mt);
    }
    ~Foo() {
    pthread_mutex_destroy(&mt);
    pthread_cond_destroy(&cv);
}

};