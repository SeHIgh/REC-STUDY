import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:google_fonts/google_fonts.dart';
import 'dart:ui' as ui;

class SignUpPage extends StatelessWidget {
  SignUpPage({super.key});

  // 폰트를 적용할 TextStyle 정의
  final TextStyle _textStyle = GoogleFonts.gaegu(
    textStyle: TextStyle(
      color: const Color(0xFF828282),
      fontSize: 14,
      fontWeight: FontWeight.w700,
    ),
  );

  @override
  Widget build(BuildContext context) {
    final Size screenSize = MediaQuery.of(context).size;

    return DefaultTextStyle(
        style: _textStyle,
        child: Scaffold(
            backgroundColor: Color(0xFFEFB411),
            body: Align(
              alignment: Alignment.center,
              child: SizedBox(
                width: screenSize.width * 0.9,
                height: screenSize.height * 0.9,
                child: Column(
                  children: [
                    Container(
                        margin: EdgeInsets.only(top: 100),
                        child: Stack(children: [
                          Positioned(
                              right: 0,
                              child: Container(
                                width: 50,
                                height: 50,
                                clipBehavior: Clip.antiAlias,
                                decoration: BoxDecoration(),
                                child:
                                    Image.asset('assets/icons/maplestory.png'),
                              )),
                          Text('Myple',
                              textAlign: TextAlign.center,
                              style: TextStyle(
                                  fontSize: 70, fontWeight: FontWeight.bold))
                        ])),
                    Container(
                      margin: EdgeInsets.only(top: 80),
                      child: SizedBox(
                        width: double.infinity,
                        height: 70,
                        child: Column(
                          mainAxisSize: MainAxisSize.min,
                          mainAxisAlignment: MainAxisAlignment.start,
                          crossAxisAlignment: CrossAxisAlignment.center,
                          children: const [
                            Text('회원가입',
                                textAlign: TextAlign.center,
                                style: TextStyle(
                                    fontSize: 28, fontWeight: FontWeight.bold)),
                            SizedBox(height: 2),
                            Text('당신의 즐거운 메이플 생활을 시작해봐요',
                                textAlign: TextAlign.center,
                                style: TextStyle(
                                    fontSize: 14, fontWeight: FontWeight.bold)),
                          ],
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(top: 20),
                      child: Container(
                        width: double.infinity,
                        height: 106,
                        decoration: BoxDecoration(
                          boxShadow: const [
                            BoxShadow(
                              color: Color(0x3F000000),
                              blurRadius: 4,
                              offset: Offset(0, 4),
                              spreadRadius: 0,
                            )
                          ],
                        ),
                        child: Column(
                          mainAxisSize: MainAxisSize.min,
                          mainAxisAlignment: MainAxisAlignment.start,
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            Container(
                                width: double.infinity,
                                height: 50,
                                padding:
                                    const EdgeInsets.symmetric(horizontal: 16),
                                decoration: ShapeDecoration(
                                  color: Color(0xFFEFB411),
                                  shape: RoundedRectangleBorder(
                                    side: BorderSide(
                                        width: 1, color: Color(0xFFDFDFDF)),
                                    borderRadius: BorderRadius.circular(8),
                                  ),
                                ),
                                child: TextField(
                                  // 커서 설정
                                  cursorHeight: 15,
                                  cursorColor: Colors.black,

                                  decoration: InputDecoration(
                                    hintText:
                                        '이메일을 입력하세요 (welcome@myple.com)', // 힌트 텍스트
                                    hintStyle: TextStyle(
                                      color: Color(0xFF828282),
                                      fontWeight: FontWeight.bold,
                                    ),
                                    border:
                                        InputBorder.none, // 텍스트 필드 주위의 테두리 제거
                                  ),
                                  style: TextStyle(
                                    color: Color(0xFF828282),
                                    fontSize: 15,
                                    fontWeight: FontWeight.bold,
                                  ),
                                )),
                            const SizedBox(height: 16),
                            Container(
                              width: double.infinity,
                              height: 40,
                              padding:
                                  const EdgeInsets.symmetric(horizontal: 16),
                              decoration: ShapeDecoration(
                                color: Colors.black,
                                shape: RoundedRectangleBorder(
                                    borderRadius: BorderRadius.circular(8)),
                              ),
                              child: Row(
                                mainAxisSize: MainAxisSize.min,
                                mainAxisAlignment: MainAxisAlignment.center,
                                crossAxisAlignment: CrossAxisAlignment.center,
                                children: const [
                                  Text(
                                    'email 로 회원가입',
                                    style: TextStyle(
                                        color: Color(0xFFEFB411),
                                        fontWeight: FontWeight.bold),
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(top: 80),
                      child: SizedBox(
                        width: double.infinity,
                        height: 126,
                        child: Stack(
                          children: [
                            Positioned(
                              left: 0,
                              top: 0,
                              child: SizedBox(
                                width: screenSize.width * 0.9,
                                height: 20,
                                child: Row(
                                  mainAxisSize: MainAxisSize.min,
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Expanded(
                                      child: Container(
                                        margin: EdgeInsets.only(right: 5),
                                        height: 1,
                                        decoration: BoxDecoration(
                                            color: Color(0xFFE6E6E6)),
                                      ),
                                    ),
                                    Text(
                                      '다른 방법도 있어요!',
                                      textAlign: TextAlign.center,
                                      style: TextStyle(
                                          color: Color(0xFF828282),
                                          fontWeight: FontWeight.bold),
                                    ),
                                    Expanded(
                                      child: Container(
                                        margin: EdgeInsets.only(left: 5),
                                        height: 1,
                                        decoration: BoxDecoration(
                                            color: Color(0xFFE6E6E6)),
                                      ),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                            Positioned(
                              left: 0,
                              top: 32,
                              child: Container(
                                width: screenSize.width * 0.9,
                                height: 40,
                                // padding:
                                //     const EdgeInsets.symmetric(vertical: 10),
                                decoration: ShapeDecoration(
                                  color: Color(0xFFEEEEEE),
                                  shape: RoundedRectangleBorder(
                                      borderRadius: BorderRadius.circular(8)),
                                  shadows: const [
                                    BoxShadow(
                                      color: Color(0x3F000000),
                                      blurRadius: 4,
                                      offset: Offset(0, 4),
                                      spreadRadius: 0,
                                    )
                                  ],
                                ),
                                child: Row(
                                  mainAxisSize: MainAxisSize.min,
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Container(
                                      width: 20,
                                      height: 20,
                                      clipBehavior: Clip.antiAlias,
                                      decoration: BoxDecoration(),
                                      child: Image.asset(
                                          'assets/icons/Google_icon.png'),
                                    ),
                                    SizedBox(width: 10),
                                    Text(
                                      'Google',
                                      style: TextStyle(
                                          fontSize: 16,
                                          color: Colors.black,
                                          fontWeight: FontWeight.bold),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                            Positioned(
                              left: 0,
                              top: 86,
                              child: Container(
                                width: screenSize.width * 0.43,
                                height: 40,
                                // padding:
                                //     const EdgeInsets.symmetric(horizontal: 35),
                                clipBehavior: Clip.antiAlias,
                                decoration: ShapeDecoration(
                                  color: Color(0xFF03C75A),
                                  shape: RoundedRectangleBorder(
                                      borderRadius: BorderRadius.circular(4)),
                                  shadows: const [
                                    BoxShadow(
                                      color: Color(0x3F000000),
                                      blurRadius: 4,
                                      offset: Offset(0, 4),
                                      spreadRadius: 0,
                                    )
                                  ],
                                ),
                                child: Row(
                                  mainAxisSize: MainAxisSize.min,
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Container(
                                      width: 16,
                                      height: 16,
                                      clipBehavior: Clip.antiAlias,
                                      decoration: BoxDecoration(),
                                      child: Image.asset(
                                          'assets/icons/Naver_icon.png'),
                                    ),
                                    SizedBox(width: 10),
                                    Text(
                                      '네이버 로그인',
                                      style: TextStyle(
                                          fontSize: 16,
                                          color: Colors.white,
                                          fontWeight: FontWeight.bold),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                            Positioned(
                              right: 0,
                              top: 86,
                              child: Container(
                                width: screenSize.width * 0.43,
                                height: 40,
                                // padding:
                                //     const EdgeInsets.symmetric(horizontal: 35),
                                clipBehavior: Clip.antiAlias,
                                decoration: ShapeDecoration(
                                  color: Color(0xFFFEE500),
                                  shape: RoundedRectangleBorder(
                                      borderRadius: BorderRadius.circular(4)),
                                  shadows: const [
                                    BoxShadow(
                                      color: Color(0x3F000000),
                                      blurRadius: 4,
                                      offset: Offset(0, 4),
                                      spreadRadius: 0,
                                    )
                                  ],
                                ),
                                child: Row(
                                  mainAxisSize: MainAxisSize.min,
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Container(
                                      width: 16,
                                      height: 16,
                                      clipBehavior: Clip.antiAlias,
                                      decoration: BoxDecoration(),
                                      child: Image.asset(
                                          'assets/icons/Kakao_icon.png'),
                                    ),
                                    SizedBox(width: 10),
                                    Text(
                                      '카카오 로그인',
                                      style: TextStyle(
                                          fontSize: 16,
                                          color: Colors.black,
                                          fontWeight: FontWeight.bold),
                                    ),
                                  ],
                                ),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                    Container(
                      margin: EdgeInsets.only(top: 10),
                      alignment: Alignment.bottomCenter,
                      child: SizedBox(
                        width: 327,
                        child: Text.rich(
                          TextSpan(
                            children: const [
                              TextSpan(
                                text: 'By clicking continue, you agree to our ',
                              ),
                              TextSpan(
                                text: 'Terms of Service',
                              ),
                              TextSpan(
                                text: ' and ',
                              ),
                              TextSpan(
                                text: 'Privacy Policy',
                              ),
                            ],
                            style: TextStyle(
                                color: Color(0xFF828282),
                                fontWeight: FontWeight.bold),
                          ),
                          textAlign: TextAlign.center,
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            )));
  }
}
