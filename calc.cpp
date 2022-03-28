#include <bits/stdc++.h>
using namespace std;
bool valid_complex(string&str);
void seperate_complex(string&str,float&real , float&img){
    int post_plus=str.find_last_of('+');
    int post_minus=str.find_last_of('-');
    int post_i=str.find('i');
    int psot_sign=max(post_minus,post_plus);
    string real_string = str.substr(1,psot_sign -1);
    real=stof(real_string);
    int img_len = str.length() -real_string.length() - 2 - 1;
    string img_string = str.substr(psot_sign, img_len);
    // cout << "real: "<<real_string << endl;
    // cout << "IMg: " << img_string << endl;
    img=stof(img_string);
}
int main() {
    string str_complex1;
    string str_complex2;
    float real1, img1,real2,img2;
    float ans_real,ans_img;
    char operation;
    while (str_complex1 != "quit") {
        cout << "please enter a valid complex number in format (real+img)or(real-img)or quit" << endl;
        cin >> str_complex1;
        cout << "enter the 2nd num" << endl;
        cin >> str_complex2;
        if (valid_complex(str_complex1)) {
            cout << "valid" << endl;

            seperate_complex(str_complex1, real1, img1);

            // cout << "num is " << real1 << "+" << img1 << endl;

        }if (valid_complex(str_complex2)){

            cout<<"valid"<<endl;
            seperate_complex(str_complex2, real2, img2);
            // cout << "num is " << real2 << "+" << img2 << endl;
            cout<<"operation : "<<endl;
            cin>>operation;
            if (operation=='+') {
                cout <<"(" <<real1 + real2 <<"+ "<< img1+img2<<"i"<<")"<<endl;
            }else if (operation=='-') {
                cout << "(" << real1 - real2 << "+ " << img1 - img2 << "i" << ")" << endl;
            }else if (operation=='*') {
                ans_real = real1*real2-img1*img2;
                ans_img = real1*img2+img1*real2;
                cout << "(" << ans_img<< "+ " << ans_real << "i" << ")" << endl;
            }else if (operation=='/') {
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
        return regex_match(str,valid_complex);

    }


