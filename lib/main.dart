import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Sehi의 첫 번째 앱'),
        ),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Container(
                width: 100,
                height: 100,
                color: Colors.blue,
                child: Center(
                  child: Text('Hello'),
                )),
            const Text('안녕~~!'),
            Icon(
              Icons.favorite,
              color: Color(0xffb1c9ef),
              size: 24.0,
            ),
            Image.asset('assets/MyFace.jpg'),
          ],
        ),
      ),
    );
  }
}
