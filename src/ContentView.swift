import SwiftUI

struct ContentView: View {
    var body: some View {
        Text(HelloTracktionWrapper().sayHello()).padding()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
