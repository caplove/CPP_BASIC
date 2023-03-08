[VS 기본 구성]
case 1. 솔루션 1개에 프로젝트 2개 (DLL과 App) 

솔루션(1) - 프로젝트(2) - 소스파일/헤더파일

math        mathDLL     - dllmain.cpp, framework.h,  pch.cpp/pch.h,   myfunc1.cpp/myfunc1.h, myfunc1.cpp/myfunc1.h

            mathApp     - mainApp.cpp/mainApp.h


![image](https://user-images.githubusercontent.com/24836829/223585091-9dce1466-664b-4edf-8915-448054114f7a.png)
![image](https://user-images.githubusercontent.com/24836829/223585107-29f19a1d-3c8c-42fc-9569-718167c56778.png)






연습: 자체 동적 연결 라이브러리 만들기 및 사용(C++)
https://learn.microsoft.com/ko-kr/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160

방법: Visual Studio의 DLL 프로젝트에서 디버그(C#, C++, Visual Basic, F#)
https://learn.microsoft.com/ko-kr/visualstudio/debugger/how-to-debug-from-a-dll-project?view=vs-2019
