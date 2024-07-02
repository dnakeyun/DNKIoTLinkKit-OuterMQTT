source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/aliyun/aliyun-specs.git'

use_frameworks!

platform :ios, '12.0'

target 'DNKIoTLinkKit' do
#  pod 'DNKIoTLinkKit', :path => '.'
pod 'DNKIoTLinkKit', :git => 'https://github.com/dnakeyun/DNKIoTLinkKit-OuterMQTT.git'

end

post_install do |installer|
  installer.generated_projects.each do |project|
    project.targets.each do |target|
      target.build_configurations.each do |config|
            config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '12.0'
           # config.build_settings['EXCLUDED_ARCHS'] = 'arm64'
           # config.build_settings['EXCLUDED_ARCHS[sdk=iphonesimulator*]'] = 'arm64'
       end
    end
  end
end
