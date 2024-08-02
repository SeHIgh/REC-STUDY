$(function(){
  let btn = $(".btn")
  let aside = $("aside")

  btn.click(function(){
    aside.toggleClass("open")

    if(aside.hasClass("open")){
      btn.find("img").attr('src','./btn_close.png')
      aside.stop().animate({right:'0'},1000,'easeInOutBack')
    }else{
      btn.find("img").attr('src','./btn_open.png')
      aside.stop().animate({right:'-400px'},1000,'easeInOutBack')
    }
  });
});
