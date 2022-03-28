//used library bits for abbreviation alot od lines
//used regex 
#include <bits/stdc++.h>
using namespace std;
bool valid_complex(string&str);
void seperate_complex(string&str,float&real , float&img){ //use a seperate function to sep the string into real and img
    int post_plus=str.find_last_of('+');  //use find function to know the place of +,-,i,real
    int post_minus=str.find_last_of('-');
    int post_i=str.find('i');
    int psot_sign=max(post_minus,post_plus);
    string real_string = str.substr(1,psot_sign -1); // will read the real numbers from the index 1 (because index zero is bracket) to position(index) of sign -1
    real=stof(real_string); //convert string to float
    int img_len = str.length() -real_string.length() - 2 - 1; //i do this algorihm to  at which the compiler know it is the start to read img numbers 
    string img_string = str.substr(psot_sign, img_len);
    img=stof(img_string);// convert string to float
}
int main() {
    
    //get the compiler complex 1 and complex 2 that consists of real1,img1,real2,img2
    
    string str_complex1;
    string str_complex2;
    float real1, img1,real2,img2;
    float ans_real,ans_img;
    char operation;
    while (str_complex1 != "quit") {
        
        //if str complex1 ="quit" then stop the programe
        
        cout << "please enter a valid complex number in format (real+img)or(real-img)or quit" << endl;
        cin >> str_complex1;
        cout << "enter the 2nd num" << endl;
        cin >> str_complex2;
        if (valid_complex(str_complex1)) {
            cout << "valid" << endl;

            seperate_complex(str_complex1, real1, img1);

        }if (valid_complex(str_complex2)){

            cout<<"valid"<<endl;
            seperate_complex(str_complex2, real2, img2);
            cout<<"operation : "<<endl;
            cin>>operation;
            if (operation=='+') {
                cout <<"(" <<real1 + real2 <<"+ "<< img1+img2<<"i"<<")"<<endl;
            }else if (operation=='-') {
                cout << "(" << real1 - real2 << "+ " << img1 - img2 << "i" << ")" << endl;
            }else if (operation=='*') {
                
                //this algorithm for multibly two complex numbers
                
                ans_real = real1*real2-img1*img2;
                ans_img = real1*img2+img1*real2;
                cout << "(" << ans_img<< "+ " << ans_real << "i" << ")" << endl;
            }else if (operation=='/') {
                
                //this algorithm for divide two complex numbers
                
                ans_real = (real1*real2+img1*img2)/((real1)*(real2)+(img2)*(img2));
                ans_img = (img1*real2+real1*img2)/((real2)*(real2)+(img2)*(img2));
                cout <<"("<<ans_real<<"+"<<ans_img<<"i"<<")" << endl;
            }
        }else {
                cout << "not valid" << endl;
         }
    }
}
    bool valid_complex(string&str){
        bool is_valid=true;
        regex valid_complex("[(](-)*+[0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)]");
        
        //used this regex algorithm to make the compiler know whats the shape of two complex brackets that must the user enter
        
        return regex_match(str,valid_complex);
        // used func match to make str=valid_complex
    }


