Pod::Spec.new do |s|
  s.name = "DNKIoTLinkKit"
  s.version = "1.0.5"
  s.summary = "不支持阿里IoT通讯，支持自定义MQTT通讯"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"cqcool"=>"cqcool@icloud"}
  s.homepage = "https://github.com/dnakeyun/dnake-specs/"
  s.source = { :http => 'https://github.com/dnakeyun/DNKIoTLinkKit-OuterMQTT.git' }
  # s.source = { :git => '/' }
  
  s.ios.deployment_target    = '12.0'
  s.ios.vendored_framework   = 'DNKIoTLinkKit.framework'
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.framework = 'SystemConfiguration'

  s.dependency 'CocoaAsyncSocket'
  s.dependency 'MQTTClient'
  s.dependency 'RealReachability'
  s.dependency 'IotLinkKit'
  s.dependency 'MJExtension'
end
