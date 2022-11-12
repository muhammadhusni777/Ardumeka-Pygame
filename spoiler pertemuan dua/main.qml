import QtQuick 2.12
import QtQuick.Window 2.13
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Extras.Private 1.0


Window {
	id : root
	width: 1200
	//maximumWidth : 1280
	//minimumWidth : width
    height: 800
	//maximumHeight : 800
	//minimumHeight : height
	title:"membuat windows"
	color : "#FF96C5"
    visible: true
    //flags: Qt.WindowMaximized //Qt.Dialog
	
	Slider{
	id : debugging_slider
	x:0
	y:0
	from : 0
	to : 90
	
	}
	
	Slider{
	id : debugging_slider2
	x:0
	y:30
	from : 0
	to : 90
	
	}
	
	
	Rectangle{
		x:120
		y:100
		width : 400
		height : 400
		color:"#444444"
		radius:20
		Rectangle{
			anchors.horizontalCenter:parent.horizontalCenter
			y: -20
			width : 200
			height : 50
			color:"Red"
			radius:20
			Text{
				anchors.horizontalCenter:parent.horizontalCenter
				anchors.verticalCenter:parent.verticalCenter
				text: "Arm Robot"
				font.pixelSize: 20
				color : "white"
				font.bold: true
			}
		}
		Rectangle{
			id: base
			x:20
			y:300
			width : 100
			height : 75
			color:"black"
			radius:20

		Rectangle{
			id: arm
			x:35
			y:70
			width : 40
			height : 180
			color:"grey"
			//rotation : gauge1.value 
			transform: Rotation { origin.x: x; origin.y: -y; angle: debugging_slider2.value - 180}
			radius:20
		
		Rectangle{
			visible:false
			x:50
			y:-110 
			width : 40
			height : 135
			color:"grey"
			rotation : debugging_slider.value
			//transform: Rotation { origin.x: 0; origin.y: 25; angle: gauge2.value}

		}
		
		Rectangle{
			id: joint
			visible:true
			x:-5
			y: 130
			width : 50
			height : 50
			color:"black"
			rotation : debugging_slider.value 
			//rotation : gauge2.value -0 
			//transform: Rotation { origin.x: 100; origin.y: 700; angle: gauge2.value}
			radius:360
		
			Rectangle{
				id: arm2
				visible:true
				x:5
				y:0
				width : 40
				height : 135
				color:"grey"
				radius:40
				//transform: Rotation { origin.x: 0; origin.y: 25; angle: gauge2.value}
					
				Image{
					id: gripper
					x:-55
					y:100
					width : 150
					height : 150
					source : "open.png"
					rotation:180
					//transform: Rotation { origin.x: 100; origin.y: 700; angle: slider1.value}

				}
			}
		
		
		
		}
		
		Rectangle{
		
		visible:true
		x:joint.x
		y: joint.y
		width : 50
		height : 50
		color:"black"
		rotation : 0 
		//rotation : gauge2.value -0 
		//transform: Rotation { origin.x: 100; origin.y: 700; angle: gauge2.value}
		radius:360
		}


	}	
		Rectangle{
			x:0
			y:0
			width : 100
			height : 75
			color:"black"
			radius:20
			}

	}
	
	
}	
	
	
	
	
}













