import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick 2.12

Item {

    visible: true

    Image {

        id: reso_icon
        width: 60
        height: 50
        visible: true
        y:300
        x:10
        source: "resolution.png"

        property int active: 0

       TapHandler{

               onTapped:all_res.visible = true


       }

    }

    Item {

        id: all_res
        visible: false
        Button{
            id: res1
            text: "640x480"
            x:80
            y:200

            onClicked:{
                camera.stop();
                camera.viewfinder.resolution = "640x480"
                camera.start();
            }


        }

        Button{
            id: res2
            text: "320x240"
            x:80
            y:250


            onClicked:{
                camera.stop();
                camera.viewfinder.resolution = "320x240"
                camera.start();
            }

        }

        Button{
            id: res3
            text: "160x120"
            x:80
            y:300
            onClicked:{
                camera.stop();
                camera.viewfinder.resolution = "160x120"
                camera.start();
            }

        }

        Button{
            id: res4
            text: "352x288"
            x:80
            y:350

            onClicked:{
                camera.stop();
                camera.viewfinder.resolution = "352x288"
                camera.start();
            }

        }

        Button{
            id: res5
            text: "176x144"
            x:80
            y:400

            onClicked:{
                camera.stop();
                camera.viewfinder.resolution = "176x144"
                camera.start();
            }

        }


    }
}
