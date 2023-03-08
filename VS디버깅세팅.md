- 기본 구조 구성

case 1. 솔루션 1개에 프로젝트 2개 (DLL과 App) 

솔루션(1) --> 프로젝트(2) --> 소스파일/헤더파일

math  -->      mathDLL   --> dllmain.cpp, framework.h,  pch.cpp/pch.h,   myfunc1.cpp/myfunc1.h, myfunc1.cpp/myfunc1.h

      -->      mathApp   --> mainApp.cpp/mainApp.h

myfunc1.cpp![image](https://user-images.githubusercontent.com/24836829/223585091-9dce1466-664b-4edf-8915-448054114f7a.png)

myfunc1.h![image](https://user-images.githubusercontent.com/24836829/223588232-3b59d0ef-09eb-49aa-80b9-2559408fc0bc.png)

mainApp.cpp![image](https://user-images.githubusercontent.com/24836829/223588156-9759887f-5cbd-4539-b655-e464f4cbb8a1.png)

[참고 사이트]

C++ DLL 프로젝트 생성 예제
https://luckygg.tistory.com/278


DLL을 탐색할 수 있는 Dependency Walker 
https://bigenergy.tistory.com/entry/%EC%B0%B8%EC%A1%B0-DLL-%EC%B0%BE%EC%95%84%EC%A3%BC%EB%8A%94-Dependency-Walker-%EC%82%AC%EC%9A%A9%EB%B2%95


DLL오류 해결 (없는 DLL 찾아 깔아줌)
https://blog.naver.com/thekernel/221681326676



[MS 홈페이지]
연습: 자체 동적 연결 라이브러리 만들기 및 사용(C++)
https://learn.microsoft.com/ko-kr/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160

방법: Visual Studio의 DLL 프로젝트에서 디버그(C#, C++, Visual Basic, F#)
https://learn.microsoft.com/ko-kr/visualstudio/debugger/how-to-debug-from-a-dll-project?view=vs-2019


[키보드로 메뉴 접근 하려면  ALT-T -->  L  --> C]

![image](https://user-images.githubusercontent.com/24836829/223589846-7304d06e-fc2f-446d-8da0-e25c15f4818c.png)


