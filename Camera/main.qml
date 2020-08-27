import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {

    visible: true
    width: 640
    height: 480



   Rectangle{
        id:window
       visible: false
       anchors.fill: parent
   }




    Camera{
        id : camera
        imageCapture {
                    onImageCaptured: {
                        // Show the preview in an Image
                        photoPreview.source = preview
                    }
                }
    }


    VideoOutput{

        source: camera
        anchors.fill: parent
    }


   Resolution{

       //An item to show resolution menu
   }



   Timer {
           id: timer
       }



   Image {
       id: timer_img
       width: 70
       height: 70
       source: "timer.png"
       x:10
       y:700


       TapHandler{

           function delay(delayTime, cb) {
                   timer.interval = delayTime;
                   timer.repeat = false;
                   timer.triggered.connect(cb);
                   timer.start();
               }


           onTapped: {

               delay(3000, function() {
                          print("And I'm printed after 1 second!")
                   camera.imageCapture.capture();
                      })
           }
       }
   }


    Image {


              id: photoPreview
              anchors.right: window.right
              anchors.bottom: window.bottom

          }

    Button{

        id:button
        width: 100
        height: 70
        text: "Capture"
        anchors.bottom: window.bottom
        anchors.horizontalCenter: window.horizontalCenter
        anchors.bottomMargin: 10



        background: Rectangle{
            color: "green"
        }

        onClicked: {

            camera.imageCapture.capture();
//            camera.stop();
//            camera.viewfinder.resolution = "176 x 144";
//            camera.start();

        }



    }




}

