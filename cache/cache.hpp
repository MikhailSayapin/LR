#include <vector>
#include <chrono>
#include <string>


struct Node
{
    unsigned int id;
    std::string name;
    int64_t time ;
    unsigned int buffer;
};

struct Cache
{
    std::vector<Node> exps;
    bool run();
};

bool Cache::run()
{
    int *array;
    unsigned int capacity = 4096;
    const unsigned int MAX_CACHE_SIZE = 11796480;
    unsigned int i = 0;
   
    
    do
    {
        array=new int[capacity];
        for(unsigned int i = 0;i < capacity-1;++i)
        {
                array[i] = i+1;
        }
        array[capacity-1] = 0;
        int t = 0;


        //прямой обход
        auto timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;++i)
        {
            for(unsigned int j=0;j<capacity;++j)
            {
                t=array[t];  
            }
        }
        auto timer_of = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        Node node{i+1,"Direct",diff,(capacity*4)/1024};
        exps.push_back(node);
        std::cout<<"number of exp: "<<node.id<<" ";
        std::cout<<"name: "<<node.name<<" ";
        std::cout<<"time: "<<node.time<<" ";
        std::cout<<"buffer: "<<node.buffer<<std::endl;
        delete[] array;

  
        
        array=new int[capacity];
        for(unsigned int i = 1; i < capacity; ++i)
        {
                array[i] = (i-1);
        }
        array[0] = capacity-1;
        t=0;
        
        
      //обратный
        timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;++i){
            for(unsigned int j = 0; j < capacity ;++j)
            {
                t=array[t];
            }
        }
        timer_of = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        Node node1{i+1,"Reverse",diff,(capacity*4)/1024};
        exps.push_back(node1);
        std::cout<<"number of exp: "<<node1.id<<" ";
        std::cout<<"name: "<<node1.name<<" ";
        std::cout<<"time: "<<node1.time<<" ";
        std::cout<<"buffer: "<<node1.buffer<<std::endl;
        delete[] array;
       
     
        
        array=new int[capacity];
        for(unsigned int i = 0;i < capacity-1;++i)
        {
                array[i] = i+1;
        }
        array[capacity-1] = 0;
        t = 0;
        
        
        for(unsigned int i = 0; i < capacity*100; ++i)
        {
            auto index1 = rand()%capacity;
            auto index2 = rand()%capacity;
            
            auto tmp = array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }
        
        
   //случайный
        timer_on = std::chrono::high_resolution_clock::now();
        for(unsigned int i=0; i < 1000 ;++i)
        {
            for(unsigned int j=0;j<capacity;++j)
            {
                t=array[t];  
            }
        }
        timer_of = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(timer_of - timer_on).count();
        Node node2{i+1,"Random",diff,(capacity*4)/1024};
        exps.push_back(node2);
        std::cout<<"number of exp: "<<node2.id<<" ";
        std::cout<<"name: "<<node2.name<<" ";
        std::cout<<"time: "<<node2.time<<" ";
        std::cout<<"buffer: "<<node2.buffer<<std::endl<<std::endl;
        
        
        capacity*=2;
        if(capacity == MAX_CACHE_SIZE)
            capacity = MAX_CACHE_SIZE*3/2;
        delete[] array;
        i++;
    }while(capacity < MAX_CACHE_SIZE*3/2);
 return true;  
}
