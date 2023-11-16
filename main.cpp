#include <iostream>
#include <thread>
#include <mutex>      
#include <chrono> 

using namespace std;

mutex mux;
bool ready = false;

// locks and increments value
void incrementValue( const int id, int numInc, int* value ) {
    int currInc = 0;
    while( !ready ){}
    while( currInc < numInc ){
        mux.lock();
        printf( "Thread #%d, value: %d\n", id, *value );
        ( *value )++;
        currInc++;
        mux.unlock();
        this_thread::sleep_for( std::chrono::microseconds(50) ); // stagger
    }
}

// Allow threads to execute
void run() {
    ready = true;
}

int main( int argc, char** argv ) { 
    // check arguments
    if ( argc <= 2 || argc > 3 ) {
        printf("Two arguments required: 1) Number of threads and 2) Number of thread increments\n");
        return 0;
    }

    // load arguments
    int  numThreads   = stoi( argv[1] );
    int  numIncrement = stoi( argv[2] );

    // spawn threads
    int  value  = 0;
    int* pValue = &value;
    thread threads[numThreads];
    for( int t(0); t < numThreads; t++ ) {
        threads[t] = thread( incrementValue, t, numIncrement, pValue );
    }

    // wait 10s
    printf("Sleeping for 10 seconds...\n");
    this_thread::sleep_for( chrono::seconds(10) );

    // run threads
    run();

    // merge with main
    for( auto& t : threads ) {
        t.join();
    }

    // done
    return 0;
}