import SwiftUI

struct ContentView: View {
    var body: some View {
        Text(helloTracker.sayHello()).padding()
        Button {
            print("Button pressed")
            helloTracker.loopTestClip()
        } label: {
            Text("Loop test clip!")
                .padding(20)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            ContentView()
                .previewInterfaceOrientation(.landscapeLeft)
        }
    }
}
