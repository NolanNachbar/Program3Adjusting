#ifndef MYHASH_
#define MYHASH_
#include <string>

template <class T>
class myHash
{
private:
    // hashsize is number you are going to decided on.
    const static int HASHSIZE = 932176;
    T *hash;
    int size;
    int collisions;
    int countOfAttempts;

public:
    myHash()
    {
        hash = new T[HASHSIZE];
        // initialize
        size = 0;
        collisions = 0;
        countOfAttempts = 0;
        for (int i = 0; i < HASHSIZE; i++)
        {
            hash[i] = "";
        }
    }; // constructor
    void insert(T item)
    {
        int key = findhash(item);
        if (hash[key].empty())
        {
            hash[key] = item;
        }
        else
        {
            collisions++;
            bool entered = false;
            int temp = 0;
            while (!entered)
            {
                temp++;
                key++;
                if (hash[key].empty())
                {
                    if (countOfAttempts < temp)
                    {
                        countOfAttempts = temp;
                        temp = 0;
                    }
                    hash[key] = item;
                    entered = true;
                    return;
                }
            }
        }
    };
    bool find(T item, double long &tempLong)
    {
        int key = findhash(item);
        tempLong++;
        if (hash[key].compare(item) == 0) // found it
        {
            return true;
        }
        else if (hash[key].empty())
        {
            return false;
        }
        bool found = false;
        int trackInc = 0;
        while (!found)
        {
            trackInc++;
            key++;
            tempLong++;
            if (hash[key].compare(item) == 0) // found it
            {
                return true;
            }
            else if (hash[key].empty() || trackInc > countOfAttempts)
            {
                return false;
            }
        }
        return false;
    }

    int getsize()
    {
        return size;
    }
    
    int findhash(std::string word)
    {
        int i;
        long int val = 0;
        for (i = 0; i <= word.size(); i++)
        {
            val += (int)word[i] * (i + 501 * (int)word[i]);
            // val += (int)word[i] * (i + 501 * (int)word[i]); 1.97 9854
            //  val += (int)word[i] * (i + 901 * (int)word[i]); 2.09 9967
            //  val += (int)word[i] * (i * 901 + (int)word[i]); 2.04 11348
            //  val += (int)word[i] * (i * 233 + (int)word[i]); 1.98 17406
            //  val += (int)word[i] * (i * 6 + 1) + 121 * word.size() * (int)word[i]; 2.3 52248
        }
        return val % HASHSIZE;
    }
    ~myHash()
    {
        delete[] hash;
    }
};
#endif
