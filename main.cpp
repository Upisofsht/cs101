#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ReplaceMyString
{
private:
    FILE *rf;
    FILE *wf;

public:
    ReplaceMyString()
    {
        rf = fopen("main.cpp", "r+");
        wf = fopen("Rmain.cpp", "w+");
    }
    void replaceString(string a, char const *b)
    {
        char readtemp;
        bool iss = false;
        int count = 0;
        int lengh = 0;
        string temp = "";
        for (int i = 0; a[i]; i++)
            lengh++;
        while ((readtemp = fgetc(rf)) != EOF)
        {
            if (iss == true)
            {
                if (readtemp == a[count])
                {
                    count++;
                    temp += readtemp;
                    if (count == lengh)
                    {
                        fprintf(wf, "%s", b);
                        count = 0;
                        temp = "";
                    }
                }
                else if (count > 0)
                {
                    fwrite(&temp[0], sizeof(char), count, wf);
                    fwrite(&readtemp, sizeof(char), 1, wf);
                    count = 0;
                    temp = "";
                }
                else
                {
                    fwrite(&readtemp, sizeof(char), 1, wf);
                }
            }
            else
            {
                fwrite(&readtemp, sizeof(char), 1, wf);
            }
            if (readtemp == '"') //"
                iss = !iss;
            cout << readtemp;
        }
    }
    ~ReplaceMyString()
    {
        fclose(rf);
        fclose(wf);
    }
};

int main()
{
    ReplaceMyString my;
    my.replaceString("IU", "IU is best");
    return 0;
}
