$(function(){
  // fadeIn, fadeOut > 투명도를 조절하면서 display none-block > 전환
  $(".box").on({
    mouseover:function(){
      $(this).find("span,p").stop().fadeIn();
    },mouseout:function(){
      $(this).find("span,p").stop().fadeOut();
    }
  })
});